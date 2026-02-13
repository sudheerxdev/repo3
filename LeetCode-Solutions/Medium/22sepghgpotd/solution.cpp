class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
          int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        vector<int> ans(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int len = right[i] - left[i] - 1;   
            ans[len] = max(ans[len], arr[i]);
        }
        for (int i = n - 1; i >= 1; i--) {
            ans[i] = max(ans[i], ans[i + 1]);
        }

        // Erase dummy 0th index
        ans.erase(ans.begin());

        return ans;
        
    }
};

