class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> freq;
        for(int num:arr){
            freq[num]++;
        }
        set<int>freqSet;

        for(auto pair:freq){
            if(freqSet.find(pair.second) != freqSet.end()){
                return false;
            }
            freqSet.insert(pair.second);
        }
        return true;


    

    }
};
