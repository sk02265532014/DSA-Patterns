// Problem: Largest Rectangle in Histogram
// Pattern: Monotonic Stack
//
// Key Idea:
// - For each bar, find the nearest smaller bar to the left and right
// - Width = rightSmallerIndex - leftSmallerIndex - 1
// - Area = height[i] * width
//
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;

        // v1[i] = index of next smaller element to the right
        // v2[i] = index of next smaller element to the left
        vector<int> v1(n), v2(n);

        // Next Smaller Element to the Right
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                v1[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            v1[st.top()] = n;
            st.pop();
        }

        // Next Smaller Element to the Left
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                v2[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            v2[st.top()] = -1;
            st.pop();
        }

        // Compute maximum area
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = v1[i] - v2[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
