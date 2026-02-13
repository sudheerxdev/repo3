class Solution {
  public:
    int findMoves(vector<int>& chairs, vector<int>& passengers) {
        // code here
        sort(chairs.begin(),chairs.end());
        sort(passengers.begin(),passengers.end());
        int moves=0;
        int n=chairs.size();
        for(int i=0;i<n;i++){
            moves+=abs(chairs[i]-passengers[i]);
        }
        return moves;
    }
};
//GFG POTD solution for 19 December
