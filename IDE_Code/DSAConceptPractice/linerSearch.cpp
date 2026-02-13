#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    bool found = false;
    for (int i = 0; i < N; i++) {
        if (A[i] == X) {
            found = true;
            break;
        }
    }
    
    if (found) cout << "YES";
    else cout << "NO";
    
    return 0;
}
