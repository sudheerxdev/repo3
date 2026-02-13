class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        sort(letters.begin() , letters.end());
        int count = 0;
        letters.erase(std::unique(letters.begin(), letters.end()), letters.end());
        if((int)target >= (int)letters[letters.size() - 1]){
            return letters[0];
        }
        // if((int)target == (int)letters[0]){
        //     return letters[letters.size() - 1];
        // }
        for(int i = 0 ; i < letters.size()-1 ; i++){
            if(letters[i]< target){
                count++;
            }
            if( letters[i]==target){
                
                return letters[i+1];
            }
        }
        return letters[count ];
    }
};
