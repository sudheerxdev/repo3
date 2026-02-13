class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0 ; 
        int right = height.size() - 1;

        int l , b ;

        int area = 0 ;
        int newarea= 0;

        while(left < right){

          int b = right - left ; 

          int l = min(height[left], height[right]);

           newarea = l* b;
          area = max(area ,newarea );

          if(height[left]<height[right]){
            left++;
          }

          else{
            right--;
          }
        }

        return area;
    }
};
