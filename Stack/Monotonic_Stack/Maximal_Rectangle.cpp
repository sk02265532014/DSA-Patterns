// Problem: Maximal Rectangle
// Pattern: Monotonic Stack + Histogram
//
// Key Idea:
// 1. Treat each row as the base of a histogram
// 2. Maintain heights of consecutive '1's column-wise
// 3. For each histogram, compute Largest Rectangle Area
//
// Subproblem: Largest Rectangle in Histogram
// - Use monotonic stack to find next smaller element
//
// Time Complexity: O(rows * cols)
// Space Complexity: O(cols)

class Solution {
public:
    // Compute largest rectangle area in a histogram
    int largestRectangleArea(vector<int> heights) {
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

        // Calculate maximum area
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = v1[i] - v2[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }

    // Main function: Maximal Rectangle in Binary Matrix
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> heights(cols, 0);
        int ans = 0;

        // Build histogram row by row
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '0')
                    heights[j] = 0;
                else
                    heights[j]++;
            }
            ans = max(ans, largestRectangleArea(heights));
        }

        return ans;
    }
};
