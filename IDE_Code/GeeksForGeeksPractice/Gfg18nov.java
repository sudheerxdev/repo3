class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        int MOD = 1e9 + 7;
        
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < roads.size(); i++) {
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        
        vector<long long> dist (n, LLONG_MAX); //Basically represents time. Here time is the weight of the edge.
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0}); //distance, node
        
        while(!pq.empty()) {
            long long distance = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            
            for (auto nbr: adj[node]) {
                int adjNode = nbr.first;
                int wt = nbr.second;
                
                if (distance + wt < dist[adjNode]) {
                    dist[adjNode] = distance + wt;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                }
                else if (distance + wt == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
};
//GFG POTD solution for 18 November
