/*
class Node {
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
    vector<int> zigZagTraversal(Node* root) {
        // code here
        vector<int> trav;
        queue<Node*> bfsQ;
        bfsQ.push(root);
        int dir=1;
        while(!bfsQ.empty()){
            int Qsize=bfsQ.size();
            vector<int> lvl;
            for(int i=0;i<Qsize;i++){
                Node* curr=bfsQ.front();
                bfsQ.pop();
                lvl.push_back(curr->data);
                if(curr->left) bfsQ.push(curr->left);
                if(curr->right) bfsQ.push(curr->right);
            }
            for(int i=0;i<Qsize;i++){
                trav.push_back(lvl[(dir==1?i:Qsize-1-i)]);
            }
            dir=!dir;
        }
        return trav;
    }
};
//GFG POTD solution for 10 October
