class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int mxPossible = *max_element(nums.begin(), nums.end());
        vector<int> freq(mxPossible + 2, 0), diff(mxPossible + 2, 0);
        
        for(auto& ele : nums){
            freq[ele]++;
            diff[max(0, ele - k)]++;
            diff[min(mxPossible, ele + k) + 1]--;
        }

        int mxFreq = 0, currFreq = 0;
        for(int i = 0; i <= mxPossible; i++){
            currFreq += diff[i];
            int finalOp = currFreq - freq[i];

            int freqPossible = finalOp > numOperations ? numOperations + freq[i] : currFreq;
            mxFreq = max(mxFreq, freqPossible);
        }
        return mxFreq;
    }
};
