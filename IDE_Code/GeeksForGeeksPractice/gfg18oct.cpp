class Solution {
    
    
    void solve(Node* root,vector<int>&ans){
        
        if(root==nullptr){
            
            return;
        }
        
        solve(root->left,ans);
        
        ans.push_back(root->data);
        
        solve(root->right,ans);
    }
  public:
    int findMedian(Node* root) {


       vector<int>ans;
       
       solve(root,ans);
       
       int n=ans.size();
       
       
       unordered_map<int,int>mpp;
       
       for(int i=0;i<n;i++){
           
           mpp[i+1]=ans[i];
       }
       
       int midvalue;
       
       if(n%2==0){
           
           midvalue=n/2;
       }
       
       else{
           
           midvalue=(n+1)/2;
       }
       
       return mpp[midvalue];
       
     
    }
};
//GFG POTD solution for 18 October
