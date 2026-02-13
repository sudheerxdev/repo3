class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // code here
         int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> op(m, vector<int>(n, -1));
        queue<pair<int,int>> q;

        // Step 1: push all 1s
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    op[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        vector<int> dx = {0,0,-1,1};
        vector<int> dy = {-1,1,0,0};

        // Step 2: BFS from all 1s
        while(!q.empty()){
            auto [x,y] = q.front(); q.pop();
            for(int k=0;k<4;k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx>=0 && nx<m && ny>=0 && ny<n && op[nx][ny]==-1){
                    op[nx][ny] = op[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return op;
    }
};
//GFG POTD solution for 28 October
