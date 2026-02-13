class Solution:
    # Function to find all possible paths
    def ratInMaze(self, maze):
        # code here
        res = []
        n = len(maze)
        
        def backtrack(row, col, path):
            if row == n-1 and col== n-1:
                res.append("".join(path))
                return
            for dr, dc, move in [(1, 0, "D"), (0, 1, "R"), (-1, 0, "U"), (0, -1, "L")]:
                nr = dr + row
                nc = dc + col
                
                if 0<=nr<n and 0<=nc<n and maze[nr][nc]==1:
                    maze[nr][nc] = 0
                    path.append(move)
                    backtrack(nr, nc, path)
                    path.pop()
                    maze[nr][nc] = 1
        if maze[0][0]==1:
            maze[0][0] = 0
            backtrack(0,0, [])
        return sorted(res)
