#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m == 0) return 0;
        int n = heightMap[0].size();
        if (n == 0) return 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        // Min heap: {height, x, y}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        // Push all boundary cells
        for (int i = 0; i < m; ++i) {
            minHeap.push({heightMap[i][0], i, 0});
            minHeap.push({heightMap[i][n - 1], i, n - 1});
            visited[i][0] = true;
            visited[i][n - 1] = true;
        }
        for (int j = 1; j < n - 1; ++j) {
            minHeap.push({heightMap[0][j], 0, j});
            minHeap.push({heightMap[m - 1][j], m - 1, j});
            visited[0][j] = true;
            visited[m - 1][j] = true;
        }

        int trappedWater = 0;
        vector<pair<int, int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        while (!minHeap.empty()) {
            vector<int> cell = minHeap.top();
            minHeap.pop();
            int height = cell[0], x = cell[1], y = cell[2];
            for (auto dir : dirs) {
                int nx = x + dir.first;
                int ny = y + dir.second;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    trappedWater += max(0, height - heightMap[nx][ny]);
                    minHeap.push({max(height, heightMap[nx][ny]), nx, ny});
                }
            }
        }
        return trappedWater;
    }
};
