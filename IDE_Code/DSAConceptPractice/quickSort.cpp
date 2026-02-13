#include<iostream>
#include<vector>
using namespace std;

int partition( vector<int>&arr , int start , int end){
    int pivot = arr[start];
    int lb = start;
    int ub = end;
    while (lb < ub) {
        while (arr[lb] <= pivot && lb < end) {
            lb++;
        }
        while (arr[ub] > pivot && ub > start) {
            ub--;
        }
        if (lb < ub) {
            swap(arr[lb], arr[ub]);
        }
    }
    swap(arr[start], arr[ub]);
    return ub;
}

void QuickSort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return ;
    }
    
    int p = partition(arr, left, right);
    QuickSort(arr, left, p -1);
    QuickSort(arr, p+1, right);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
    QuickSort(arr, 0, n - 1);
    cout << "After the sorting the array is: ";
    for (int i = 0 ; i < n ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
