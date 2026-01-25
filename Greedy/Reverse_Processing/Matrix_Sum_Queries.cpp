// Problem: Sum of Matrix After Queries
// Pattern: Greedy + Reverse Processing
//
// Key Idea:
// - Only the LAST operation on a row or column matters
// - Process queries from the end
// - Track which rows and columns are already finalized
// - When processing a row update, it affects all remaining columns
// - When processing a column update, it affects all remaining rows
//
// Time Complexity: O(q + n)
// Space Complexity: O(n)

class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        vector<bool> rowDone(n, false), colDone(n, false);

        int rowLeft = n, colLeft = n;
        long long sum = 0;

        // Process queries in reverse
        for (int i = queries.size() - 1; i >= 0; i--) {
            int type = queries[i][0];
            int index = queries[i][1];
            int val = queries[i][2];

            if (type == 0) { // row update
                if (!rowDone[index]) {
                    sum += 1LL * val * colLeft;
                    rowDone[index] = true;
                    rowLeft--;
                }
            } else { // column update
                if (!colDone[index]) {
                    sum += 1LL * val * rowLeft;
                    colDone[index] = true;
                    colLeft--;
                }
            }
        }
        return sum;
    }
};
