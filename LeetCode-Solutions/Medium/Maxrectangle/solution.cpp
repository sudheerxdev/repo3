class Solution {
  public:
   vector<int>ps(vector<int>rect){
       int n = rect.size();
       vector<int>ans(n, -1);
       stack<int>st;
       st.push(0);
       for( int i =1 ; i< n ; i++){
           while(!st.empty() && rect[st.top()] >= rect[i]) st.pop();
           
           if(!st.empty())ans[i]=st.top();
           st.push(i);
       }
       return ans;
   }
   
     vector<int>ns(vector<int>rect){
       int n = rect.size();
       vector<int>ans(n, n);
       stack<int>st;
       st.push(n-1);
       for( int i =n-2 ; i>= 0 ; i--){
           while(!st.empty() && rect[st.top()]>= rect[i]) st.pop();
           if(!st.empty())ans[i]=st.top();
           st.push(i);
       }
       return ans;
   }
   
   
   
    int maxArea(vector<vector<int>> &mat) {
        // code here
        int ans =0; 
        int n = mat.size();
        int m = mat[0].size();
        vector<int>temp(m,0);
        for( int i =0;i<n ; i++ ){
            for(int j =0; j<m ; j++){
                if(mat[i][j]==0)temp[j]=0;
                else{
                    temp[j]+=1;
                }
            }
            vector<int>p1=ps(temp);
            vector<int>n1=ns(temp);
            
            for(int k =0; k< m ; k++){
                  // cout<<p1[k]<<"-"<<n1[k]<<" ";
                  // cout<<temp[k]<<" ";
              ans = max( ans  , (n1[k]-p1[k]-1)*temp[k])  ;
            }
         // cout<<"\n";  
        }
        
        return ans ;
    }
};
