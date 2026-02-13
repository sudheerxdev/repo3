/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> helper(Node* root)
    {
        if(root==nullptr) return {0,0};
        
        vector<int>lt=helper(root->left);
        vector<int>rt=helper(root->right);
        
        int withRoot=root->data+lt[1]+rt[1];
        int withOutRoot=max(lt[0],lt[1])+max(rt[0],rt[1]);
        
        return {withRoot,withOutRoot};
    }
    int getMaxSum(Node *root) {
        // code here
        vector<int>ans=helper(root);
        return max(ans[0],ans[1]);
    }
};
//GFG POTD solution for 13 October
