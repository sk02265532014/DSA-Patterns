// Problem: Final Prices With a Special Discount
// Pattern: Monotonic Stack (Next Smaller Element)
//
// Key Idea:
// - For each price, find the next price to the right
//   that is less than or equal to it
// - Use a monotonic increasing stack of indices
//
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> st;

        for (int i = 0; i < n; i++) {
            // Apply discount to all previous prices
            // that are >= current price
            while (!st.empty() && prices[st.top()] >= prices[i]) {
                prices[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }
        return prices;
    }
};
