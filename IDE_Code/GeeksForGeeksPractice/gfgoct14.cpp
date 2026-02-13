/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  int ans=0;
  void solve(Node *root,int low,int high){
    if(root==NULL)return ;
    if(root->data>=low&&root->data<=high)ans+=root->data; ;
    solve(root->left,low,high);
    solve(root->right,low,high);
    return ;
}
    int nodeSum(Node* root, int l, int r) {
        // code here
        
        solve(root,l,r);
        return ans;
    }
};

//GFG POTD solution for 14 October
