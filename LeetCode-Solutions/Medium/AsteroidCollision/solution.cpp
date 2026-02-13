class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        bool flag=false;
        for (int i = 0; i < asteroids.size(); i++) {
            int current = asteroids[i];

            // If the current asteroid is moving right or stack is empty, just push it
            if (current > 0) {
                st.push(current);
            } else {
                // If the current asteroid is moving left, check for possible collisions
                while (!st.empty() && st.top() > 0) {
                    // If the current asteroid is larger, pop the stack (destroy the top)
                    if (st.top() < abs(current)) {
                        st.pop();
                    }
                    // If they are equal in size, both are destroyed
                    else if (st.top() == abs(current)) {
                        st.pop();
                        flag=true;
                        
                        break; // Both asteroids are destroyed
                    }
                    // If the current asteroid is smaller, it is destroyed
                    else {
                        break;
                    }
                }
                // If the current asteroid hasn't been destroyed, push it to the stack
                if ((st.empty() || st.top() < 0) && !flag) {
                    st.push(current);
                    
                }
                else{
                    flag=false;
                }
            }
        }

        // Collect the remaining asteroids in the stack
        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        // The result should be in reverse order
        reverse(result.begin(), result.end());
        return result;
    }
};
