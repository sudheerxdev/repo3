class Solution {
  public:
    int andInRange(int l, int r) {
        // code here
       int shift = 0;
        
        while (l < r) {
            l >>= 1;
            r >>= 1;
            shift++;
        }
        
        return l << shift;
    }
};

//GFG POTD solution for 26 November
