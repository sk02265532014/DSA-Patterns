// Problem: Remove K Digits
// Pattern: Greedy + Monotonic Stack
//
// Key Idea:
// - Maintain a monotonic increasing stack (as a string)
// - Remove digits greedily when a smaller digit appears
// - If removals remain, remove from the end
// - Trim leading zeros from the result
//
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    string removeKdig(string& s, int k) {
        string st;

        // Build monotonic increasing stack
        for (char ch : s) {
            while (!st.empty() && k > 0 && st.back() > ch) {
                st.pop_back();
                k--;
            }
            st.push_back(ch);
        }

        // Remove remaining digits from the end
        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }

        // Remove leading zeros
        int idx = 0;
        while (idx < st.size() && st[idx] == '0')
            idx++;

        st = st.substr(idx);

        return st.empty() ? "0" : st;
    }
};
