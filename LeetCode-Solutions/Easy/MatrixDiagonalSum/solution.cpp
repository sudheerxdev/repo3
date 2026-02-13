class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0 ; 
        int n = mat.size() - 1;
        if(n % 2!= 0){
            for(int i = 0 ; i <= n ; i++){
             sum += (mat[i][i] + mat[i][n - i]);
            }
        }
        else{
              for(int i = 0 ; i <= n ; i++){
                sum += (mat[i][i] + mat[i][n - i]);
            }
             sum = sum - mat[n/2][n/2];
        }
        return sum;
    }
};
