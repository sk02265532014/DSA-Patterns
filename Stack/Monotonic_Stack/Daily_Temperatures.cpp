// Problem: Daily Temperatures
// Pattern: Monotonic Stack (Next Greater Element)
//
// Key Idea:
// - Maintain a stack of indices with decreasing temperatures
// - When a warmer temperature is found, resolve all previous colder days
//
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st;  // stores indices

        for (int i = 0; i < n; i++) {
            // Resolve previous colder temperatures
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                int idx = st.top();
                st.pop();
                ans[idx] = i - idx;
            }
            st.push(i);
        }
        return ans;
    }
};
