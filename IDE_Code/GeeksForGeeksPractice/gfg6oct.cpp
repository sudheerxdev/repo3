class Solution {
  public:
  
    vector<vector<int>> dir = {{-2, 1}, {-2, -1}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {1, 2}, {1, -2}};
  
    void tourUtl(vector<vector<int>> &path, int n, int i, int j, int step, bool &ifAllVisited){
        
        //check boundary condition
        if(i<0 or j<0 or i>=n or j>=n)
            return;
            
        //check if already visited
        if(path[i][j] != -1)
            return;
            
        path[i][j] = step;
        
        if(step == n*n-1){
            ifAllVisited = true;
            return;
        }
        
        for(int d=0; d<8; d++){
            
            int iNext = i + dir[d][0];
            int jNext = j + dir[d][1];
            
            tourUtl(path, n, iNext, jNext, step+1, ifAllVisited);
            
            if(ifAllVisited == true)
                return;
        }
        
        //reset the path
        path[i][j] = -1;
    }
  
    vector<vector<int>> knightTour(int n) {
        // code here
        vector<vector<int>> path(n,vector<int> (n, -1));
        
        bool ifAllVisited = false;
        
        tourUtl(path, n, 0, 0, 0, ifAllVisited);
        
        if(ifAllVisited == false)
            return {{-1}};
        
        return path;
    }
};
//GFG POTD solution for 06 October
