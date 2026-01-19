// Problem: Search a 2D Matrix
// Pattern: Binary Search (Index Mapping)
//
// Key Idea:
// - Treat the 2D matrix as a flattened sorted array
// - Map 1D index -> 2D coordinates using:
//     row = mid / number_of_columns
//     col = mid % number_of_columns
//
// Time Complexity: O(log(m * n))
// Space Complexity: O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int left = 0, right = rows * cols - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int value = matrix[mid / cols][mid % cols];

            if (value == target)
                return true;
            else if (value < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};
