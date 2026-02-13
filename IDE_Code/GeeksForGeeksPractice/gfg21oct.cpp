class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        unordered_map<int,int> ct;
        map<int,set<int>> mp;
        for(auto it : arr)
        {
            // if(ct[it])
            // {
                mp[ct[it]].erase(it);
                if(mp[ct[it]].empty())
                mp.erase(ct[it]);
            // }
            ct[it]++;
            mp[ct[it]].insert(it);
        }
        vector<int> res;
        while(k--)
        {
            int maxCt = mp.rbegin()->first;
            int num = *(mp[maxCt].rbegin());
            res.push_back(num);
            mp[maxCt].erase(num);
            if(mp[maxCt].empty())
            mp.erase(maxCt);
        }
        return res;
    }
};

//GFG POTD solution for 21 October
