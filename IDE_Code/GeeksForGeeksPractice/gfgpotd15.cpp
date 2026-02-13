/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  
  void solve(Node* root, int k, int &ans, int &count){
      if(root == NULL) return;
      solve(root->left, k, ans, count);
      count++;
      if(count == k){
          ans = root->data;
          return;
      }
      solve(root->right, k, ans, count);
  }
  
    int kthSmallest(Node *root, int k) {
        // code here
        int ans = -1;
        int count = 0;
        
        solve(root, k, ans, count);
        
        return ans;
    }
};
//GFG POTD solution for 15 October
