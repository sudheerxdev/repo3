class Solution {
  public:
    int findParent(vector<int> &parent, int node) {
            if(parent[node] == node) {
                return node;
            }
            return parent[node] = findParent(parent, parent[node]);   //path compression
        }
        
        void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
            u = findParent(parent, u);
            v = findParent(parent, v);
            
            if(rank[u] < rank[v]) {
                parent[u] = v;
                rank[u]++;
            }
            else {
                parent[v] = u;
                rank[v]++;
            }
        }
        
        int minConnect(int n , vector<vector<int>> &connections)
        {
            vector<int> rank(n);
            vector<int> parent(n, 0);
            
            for(int i = 0; i < n; i++) {
                parent[i] = i;
            }
            
            int noExtraEdges = 0;
            for(auto connection : connections) {
                int u = connection[0];
                int v = connection[1];
                
                u = findParent(parent, u);
                v = findParent(parent, v);
                
                if(u != v) {
                    unionSet(u, v, parent, rank);
                }
                else {
                    ++noExtraEdges;
                }
            }
            
            int nocc = 0;
            for(int i = 0; i < n; i++) {
                if(parent[i] == i) ++nocc;
            }
            
            int ans = nocc - 1;
            return noExtraEdges >= ans ? ans : -1;
        }
};

//GFG POTD solution for 22 November
