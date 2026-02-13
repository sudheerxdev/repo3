#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void merge(vector<int>&arr , int low , int mid , int high){
    int i = low , j = mid + 1;
    vector<int>temp;
    while(i <= mid && j <= high){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i++]);
        }
        else{
            temp.push_back(arr[j++]);
        }
    }
    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    while(j<=high){
        temp.push_back(arr[j++]);
    }
    for(size_t k = 0 ; k < temp.size() ; k++){
        arr[low +k]=temp[k];
    }
}
void mergesort(vector<int>&arr , int low  , int high){
    if(low >= high)return ;
    int mid = low + (high - low)/2;
    mergesort(arr , low , mid);
    mergesort(arr , mid + 1, high);
    merge(arr , low , mid , high);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n ; 
    cin >> n ; 
    vector<int>arr;
    for(int i = 0 ; i < n ; i++){
        int num ; 
        cin >> num;
        arr.push_back(num);
    }
    mergesort(arr , 0 , arr.size() -1);
    cout << "[";
    for(size_t i = 0 ; i < arr.size() ; i++){
        cout << arr[i] ;
        if (i != arr.size() - 1) cout << ",";
    }
    cout << "]";
    return 0;
}
