#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left;
    int j = mid + 1;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }
    // Copy remaining elements
    while (i <= mid) {
        temp.push_back(arr[i++]);
    }
    while (j <= right) {
        temp.push_back(arr[j++]);
    }
    // Copy all elements back
    for (int k = left; k <= right; k++) {
        arr[k] = temp[k - left];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return ;
    }
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
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
    mergeSort(arr, 0, n - 1);
    cout << "After the sorting the array is: ";
    for (int i = 0 ; i < n ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
