class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        queue<tuple<int, int, int>> q;
        q.push({entrance[0], entrance[1], 0});
        maze[entrance[0]][entrance[1]] = '+'; 

        while (!q.empty()) {
            auto [x, y, steps] = q.front();
            q.pop();

            for (auto& dir : directions) {
                int newX = x + dir[0], newY = y + dir[1];

                if (newX >= 0 && newX < m && newY >= 0 && newY < n && maze[newX][newY] == '.') {
                    if (newX == 0 || newX == m - 1 || newY == 0 || newY == n - 1) {
                        return steps + 1;
                    }
                    maze[newX][newY] = '+'; 
                    q.push({newX, newY, steps + 1});
                }
            }
        }

        return -1;
    }
};
