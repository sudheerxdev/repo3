#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int partition(vector<int>&arr , int low , int high){
    int i = low , j = high ; 
    int pivot = arr[low];
    while(i <= j){
        while(arr[i]<=pivot && i <= high) i++;
        while(arr[j]>pivot) j--;
        if(i < j){
            swap(arr[i],arr[j]);
        }
       
    }
    swap(arr[j] , arr[low]);
    return j;
}
void QuickSort(vector<int>&arr , int low , int high){
    if(low >= high)return ; 
    int pidx = partition(arr , low , high);
    QuickSort(arr , low , pidx -1);
    QuickSort(arr , pidx + 1, high);
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n ;
   // cout << "enter the size of the array ";
    cin >> n ; 
    vector<int>arr ; 
   // cout << "enter the element of the array ";
    for(int i = 0 ; i < n ; i++){
        int num ; 
        cin >> num ; 
        arr.push_back(num);
    }
    QuickSort(arr , 0 , arr.size() -1);
    cout << "[";
    for(size_t i = 0 ; i < arr.size() ; i++){
        cout << arr[i];
        if(i!=arr.size()-1)cout << ",";
    }
    cout << "]";
    
    return 0;
}
