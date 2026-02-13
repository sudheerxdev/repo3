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
        vector<long long> heights(N);
        for (int i = 0; i < N; i++) {
            cin >> heights[i];
        }
        cout << *max_element(heights.begin(), heights.end()) << "\n";
    }
    return 0;
}
