class Solution {
public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        int n = arr.size();
        int a = 0, b = 0;
        int l = 0;

        multiset<int> s;

        for (int i = 0; i < n; i++) {
            s.insert(arr[i]);
            int mn = *s.begin();
            int mx = *s.rbegin();

            while (mx - mn > x) {
                s.erase(s.find(arr[l]));
                l++;
                mn = *s.begin();
                mx = *s.rbegin();
            }

            if (i - l > b - a) { // longer window found
                a = l;
                b = i;
            }
        }

        vector<int> ans;
        for (int k = a; k <= b; k++) ans.push_back(arr[k]);
        return ans;
    }
};

//GFG POTD solution for 28 September
