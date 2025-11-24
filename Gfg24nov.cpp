class Solution {
public:

    struct DSU {
        vector<int> parent, rankv;
        DSU(int n) {
            parent.resize(n);
            rankv.resize(n, 0);
            for (int i = 0; i < n; i++) parent[i] = i;
        }
        int find(int x) {
            if (parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        }
        bool unite(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) return false;
            if (rankv[a] < rankv[b]) swap(a, b);
            parent[b] = a;
            if (rankv[a] == rankv[b]) rankv[a]++;
            return true;
        }
    };

    // Function to find MST excluding one edge index
    int mstExcludingEdge(int V, vector<vector<int>>& edges, int forbiddenIdx) {
        DSU dsu(V);
        int weight = 0, cnt = 0;

        for (int i = 0; i < edges.size(); i++) {
            if (i == forbiddenIdx) continue;

            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            if (dsu.unite(u, v)) {
                weight += w;
                cnt++;
            }
        }

        if (cnt != V - 1) return INT_MAX;   // Not a valid MST
        return weight;
    }

    int secondMST(int V, vector<vector<int>> &edges) {

        sort(edges.begin(), edges.end(),
             [](auto &a, auto &b){ return a[2] < b[2]; });

        DSU dsu(V);
        int mstWeight = 0;
        vector<int> mstEdges; // store indices of edges used in MST

        // Step 1: build MST
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            if (dsu.unite(u, v)) {
                mstWeight += w;
                mstEdges.push_back(i);
            }
        }

        if (mstEdges.size() != V - 1) return -1; // MST not possible

        int secondBest = INT_MAX;

        // Step 2: Try removing each MST edge
        for (int idx : mstEdges) {
            int val = mstExcludingEdge(V, edges, idx);
            if (val > mstWeight)
                secondBest = min(secondBest, val);
        }

        if (secondBest == INT_MAX) return -1;
        return secondBest;
    }
};

//GFG POTD solution for 24 November
