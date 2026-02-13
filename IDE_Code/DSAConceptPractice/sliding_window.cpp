#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>arr;
    int n ; 
    cin >> n ;
    for(int i = 0 ; i < n ; i++){
        int x; 
        cin >> x;
        arr.push_back(x);
    }
    int k = 4;
    int i = 0, j = 3, sum = 0, maxsum = 0;
    sum = arr[0] + arr[1]  + arr[2] + arr[3];
    maxsum = max(maxsum , sum);
    for(int j = 4 ; j < n ; j++){
        sum += arr[j];
        sum = sum - arr[i];
        maxsum = max(maxsum , sum);
        //sum = sum - arr[i];
        i++;
    }
    cout << maxsum << endl;
    
}