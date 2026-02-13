#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

inline long long addmod(long long a, long long b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}
inline long long mulmod(long long a, long long b) {
    return (a * b) % MOD;
}

// contribution of a cycle of length L
long long cycleContribution(int L, int N) {
    if (L == 1) return 0; // nothing to fix
    
    long long ans = 0;
    for (int A = 1; A <= N; A++) {
        long long k = (1LL * L * A) / (L - 1);
        if (k > N) k = N;

        long long part1 = mulmod((L - 1), (1LL * k * (k + 1) / 2) % MOD);
        long long part2 = mulmod((N - k), mulmod(L, A));
        ans = (ans + part1 + part2) % MOD;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> P(N+1);
        for (int i = 1; i <= N; i++) cin >> P[i];

        vector<int> vis(N+1, 0);
        vector<int> cycles;
        for (int i = 1; i <= N; i++) {
            if (!vis[i]) {
                int cnt = 0, cur = i;
                while (!vis[cur]) {
                    vis[cur] = 1;
                    cur = P[cur];
                    cnt++;
                }
                cycles.push_back(cnt);
            }
        }

        long long ans = 0;
        for (int L : cycles) {
            ans = (ans + cycleContribution(L, N)) % MOD;
        }
        cout << ans << "\n";
    }
    return 0;
}
