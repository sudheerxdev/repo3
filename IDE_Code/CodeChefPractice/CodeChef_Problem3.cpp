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
        string S; 
        cin >> S;

        bool ok = true;

        for (int i = 0; i < N;) {
            if (S[i] == '1') {
                int j = i;
                while (j < N && S[j] == '1') j++;
                int len = j - i;
                if (len < 3) ok = false;
                i = j;
            } else {
                i++;
            }
        }

        cout << (ok ? "Yes\n" : "No\n");
    }
    return 0;
}
