/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
   
    int fun(Node *root, int &ans){
        if(!root)
          return 0;
        int l = fun(root->left, ans);
        int r = fun(root->right, ans);
        
        int maxi = max({0, l, r});
        
        int t1 = (root->data) + maxi;
        int t2 = (root->data) + l + r;
        
        ans = max(ans, max(t1, t2));
        
        return maxi + (root->data);
        
    }
    
    
    int findMaxSum(Node *root) {
        // code here
        int ans = INT_MIN;
        fun(root, ans);
        return ans;
    }
};

