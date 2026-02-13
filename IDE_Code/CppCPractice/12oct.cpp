/*
    class Node {
    public:
        int data;
        Node* left;
        Node* right;
    
        Node(int x) {
            data = x;
            left = right = nullptr;
        }
    };
    */
    
    class Solution {
      public:
      int moves = 0;

        int dfs(Node* root) {
        if (!root) return 0;

        int leftExcess = dfs(root->left);   
        int rightExcess = dfs(root->right); 
        moves += abs(leftExcess) + abs(rightExcess); 
        return root->data - 1 + leftExcess + rightExcess;
    }

        int distCandy(Node* root) {
            // your code here
            moves = 0;
            dfs(root);
            return moves;
        }
    };


//GFG POTD solution for 12 October
