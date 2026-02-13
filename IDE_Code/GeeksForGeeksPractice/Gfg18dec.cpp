class Solution {
  public:
    void sortIt(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
        int id_even=arr.size()-1;
        int id_odd=0;
        vector<int>ans(arr.size());
        for(int i=arr.size()-1;i>=0;i--){
            if(arr[i]%2==0){
                ans[id_even]=arr[i];
                id_even--;
            }
            else{
                ans[id_odd]=arr[i];
                id_odd++;
            }
        }
        arr=ans;
        
        
    }
};
//GFG POTD solution for 18 December
