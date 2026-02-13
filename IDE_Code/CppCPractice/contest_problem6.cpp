#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        unordered_map<int,int> freq;
        for (int i = 0; i < N; i++) {
            cin >> A[i];
            freq[A[i]]++;
        }

        // Option 1: only single-fence paints
        int ans = 0;
        for (int x : A) if (x != 1) ans++;

        // Option 2: 1 global + fixes
        for (auto &p : freq) {
            int X = p.first;
            int cntSame = p.second;
            ans = min(ans, 1 + (N - cntSame));
        }

        cout << ans << "\n";
    }
    return 0;
}
