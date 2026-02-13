class Solution {
  public:
    void merge(vector<int>&arr , int left , int mid , int right){
        vector<int> ans;
        int i = left , j = mid + 1;
        while(i <= mid && j <= right){
            if(arr[i]<=arr[j]){
                ans.push_back(arr[i++]);
               // i++;
               
            }
            // else if(arr[i]<arr[j]){
            //     ans.push_back(arr[i]);
            //     i++;
            // }
            else{
                ans.push_back(arr[j]);
                j++;
            }
        }
       
            while(j <= right){
                ans.push_back(arr[j]);
                j++;
          
            }
       
            while(i <= mid){
                 ans.push_back(arr[i]);
                 i++;
            }
           
        for(int k = 0 ; k < ans.size() ; k++){
            arr[k + left]=ans[k];
        }
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l >= r)return ; 
        int mid = l +(r - l)/2;
        mergeSort( arr , l , mid);
        mergeSort(arr , mid + 1 , r);
        merge(arr , l , mid , r);
        
    }
};
