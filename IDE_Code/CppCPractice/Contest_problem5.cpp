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

        vector<vector<int>> A(N, vector<int>(N));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                A[i][j] = (i + j) % N; // 0-indexed formula
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << A[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
