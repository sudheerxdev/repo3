class Solution {
public:
    int countOdds(int low, int high) {
        int count = 0;
        while(low % 2 == 0){
            low++;
        }
        while(high % 2 ==0){
            high--;
        }
        for(int i = low ; i <= high ; i+=2){
            count ++;
        }
        return count;
    }
};
