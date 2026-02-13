#include <stdio.h>
#include <string.h>

#define MOD 1000000007L
#define MAXM 31
#define MAXBITS 31
#define MAXOVER 16

static long dp[MAXM][MAXBITS][MAXOVER];
static int choose[MAXM][MAXM];

static void precompute_choose() {
    for (int n = 0; n < MAXM; n++) {
        choose[n][0] = choose[n][n] = 1;
        for (int k = 1; k < n; k++) {
            choose[n][k] = (choose[n - 1][k] + choose[n - 1][k - 1]) % MOD;
        }
    }
}

static inline int popcount(int x) {
    int c = 0;
    while (x) {
        x &= (x - 1);
        c++;
    }
    return c;
}

int magicalSum(int M, int K, int* nums, int numsSize) {
    memset(dp, 0, sizeof(dp));
    precompute_choose();

    dp[0][0][0] = 1;

    for (int i = 0; i < numsSize; i++) {
        for (int length = M; length >= 0; length--) {
            long power = 1;
            for (int added = 1; added + length <= M; added++) {
                power = (power * nums[i]) % MOD;
                long value = (power * choose[length + added][added]) % MOD;

                for (int bits = length; bits >= 0; bits--) {
                    for (int overflow = 0; overflow <= (length - bits) / 2; overflow++) {
                        int tail_bits = added + overflow;
                        int nb = bits + (tail_bits & 1);
                        int no = tail_bits >> 1;

                        dp[length + added][nb][no] =
                            (dp[length + added][nb][no] +
                             dp[length][bits][overflow] * value) % MOD;
                    }
                }
            }

            for (int bits = length; bits >= 0; bits--) {
                for (int overflow = 1; overflow <= (length - bits) / 2; overflow++) {
                    int nb = bits + (overflow & 1);
                    int no = overflow >> 1;

                    dp[length][nb][no] =
                        (dp[length][nb][no] + dp[length][bits][overflow]) % MOD;

                    dp[length][bits][overflow] = 0;
                }
            }
        }
    }

    long total = 0;
    for (int overflow = 0; overflow <= M / 2; overflow++) {
        int ob = popcount(overflow);
        if (ob <= K) {
            total = (total + dp[M][K - ob][overflow]) % MOD;
        }
    }

    return (int)total;
}
