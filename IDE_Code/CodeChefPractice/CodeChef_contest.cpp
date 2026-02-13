#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int A, B;
        cin >> A >> B;
        int usable_syrup = min(A, B / 2);
        cout << 3 * usable_syrup << "\n";
    }
    return 0;
}
