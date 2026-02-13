class Solution {
  public:
 
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        // code here
        int x=(V*(V-1)/2);
        return x-edges.size();
    }
};

//GFG POTD solution for 02 November
