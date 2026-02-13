#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    vector<long long> A(N+1), B(N+1);
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) cin >> B[i];
    
    long long sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += min(A[i], B[i]);
    }
    
    while (Q--) {
        char c;
        int x;
        long long v;
        cin >> c >> x >> v;
        
        long long old_val = min(A[x], B[x]);
        if (c == 'A') A[x] = v;
        else B[x] = v;
        long long new_val = min(A[x], B[x]);
        
        sum += (new_val - old_val);
        cout << sum << "\n";
    }
}