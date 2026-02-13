class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        // code here
        int n=arr.size();
    
    vector<int>cntdigit(n,0);
    
    int cnt=1;
    
    cntdigit[0]=n;
    
    int xr=0;
    
    if(n%2!=0)
     xr=arr[0];
    
    for(int i=1;i<n;i++){
        
        cntdigit[i]=n-i+cntdigit[i-1]-cnt;

        if(cntdigit[i]%2!=0){
        xr=xr^arr[i];
        }
        
        cnt++;
    }
    
    return xr;
    }
};
//GFG POTD solution for 25 November
