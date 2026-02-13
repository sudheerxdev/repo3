#include <bits/stdc++.h>
using namespace std;

struct State {
    int r, c, t, d; // row, col, toggle_state, distance
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    cin >> H >> W;
    vector<string> grid(H);
    for (int i = 0; i < H; i++) cin >> grid[i];

    int sr, sc, gr, gc;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == 'S') sr = i, sc = j;
            if (grid[i][j] == 'G') gr = i, gc = j;
        }
    }

    vector<vector<vector<bool>>> vis(H, vector<vector<bool>>(W, vector<bool>(2, false)));
    queue<State> q;
    q.push({sr, sc, 0, 0});
    vis[sr][sc][0] = true;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [r, c, t, d] = q.front();
        q.pop();

        if (r == gr && c == gc) {
            cout << d << "\n";
            return 0;
        }

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            int nt = t;
            if (nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
            char cell = grid[nr][nc];
            if (cell == '#') continue;

            if (cell == '?') nt ^= 1; // toggle doors
            else if (cell == 'x' && nt == 0) continue; // closed, not passable
            else if (cell == 'o' && nt == 1) continue; // toggled, closed

            if (!vis[nr][nc][nt]) {
                vis[nr][nc][nt] = true;
                q.push({nr, nc, nt, d + 1});
            }
        }
    }

    cout << -1 << "\n";
    return 0;
}