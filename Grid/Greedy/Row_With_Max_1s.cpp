// Problem: Row with Maximum 1s
// Pattern: Greedy Staircase Search (Sorted Rows)
//
// Key Idea:
// - Rows are sorted (0s followed by 1s)
// - Start from top-right corner
// - Move left on seeing 1
// - Move down on seeing 0
//
// Time Complexity: O(m + n)
// Space Complexity: O(1)

class Solution {
public:
    int rowWithMax1s(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();

        int row = 0;
        int col = n - 1;
        int ans = -1;

        while (row < m && col >= 0) {
            if (arr[row][col] == 1) {
                ans = row;   // found a row with more 1s
                col--;       // try to find even more 1s
            } else {
                row++;       // move to next row
            }
        }
        return ans;
    }
};
