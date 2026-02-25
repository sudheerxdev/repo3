#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int INV2 = 499122177;

void solve() {
    int n;
    cin >> n;

    // Adjacency list
    vector<vector<int>> a(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    // parent, subtree size, bfs order
    vector<int> p(n + 1, 0);
    vector<int> s(n + 1, 1);
    vector<int> o;
    o.reserve(n);

    // BFS from node 1
    vector<int> q;
    q.push_back(1);

    int h = 0;
    while (h < (int)q.size()) {
        int u = q[h++];
        o.push_back(u);

        for (int v : a[u]) {
            if (v != p[u]) {
                p[v] = u;
                q.push_back(v);
            }
        }
    }

    // Compute subtree sizes (reverse order)
    for (int i = n - 1; i >= 0; i--) {
        int u = o[i];
        if (p[u] != 0) {
            s[p[u]] += s[u];
        }
    }

    long long ans = (n + 1LL * n * (n - 1) / 2) % MOD;
    long long t = 1LL * (n - 1) * (n - 1) % MOD;

    for (int i = 1; i <= n; i++) {
        long long w = 1;
        long long sq = 0;

        for (int v : a[i]) {
            long long c = (v == p[i]) ? (n - s[i]) : s[v];
            w = w * (c + 1) % MOD;
            sq = (sq + c * c) % MOD;
        }

        long long w2 = (t - sq + MOD) % MOD * INV2 % MOD;
        long long cur = (2 * w % MOD - 2 * n % MOD - w2) % MOD;
        cur = (cur + MOD) % MOD;

        ans = (ans + cur) % MOD;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
