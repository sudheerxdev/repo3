/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node *constructTree(vector<int> &pre, vector<int> &post) {
        return MakeTheTree(pre, post, 0, pre.size()-1, 0);
        
    }
    
    Node* MakeTheTree(vector<int>& pre, vector<int>&post, int preStart, int preEnd, int postStart){
        if(preStart>preEnd) return NULL;
        Node* root= new Node(pre[preStart]);
        if(preStart==preEnd) return root;
        int postEnd = postStart;
        while(post[postEnd]!=pre[preStart+1]){
            postEnd++;
        }
        int num = postEnd-postStart+1;
        root->left = MakeTheTree(pre, post, preStart+1, preStart+num, postStart);
        root->right=MakeTheTree(pre, post, preStart+num+1, preEnd, postEnd+1);
        return root;
    }
};
//GFG POTD solution for 08 October
