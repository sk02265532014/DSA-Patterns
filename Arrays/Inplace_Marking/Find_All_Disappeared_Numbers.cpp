// Problem: Find All Numbers Disappeared in an Array
// Pattern: In-place Array Marking
//
// Key Idea:
// - Numbers are in range [1, n]
// - Use each value as an index and mark the corresponding position negative
// - After marking, indices with positive values indicate missing numbers
//
// Time Complexity: O(n)
// Space Complexity: O(1) (excluding output array)

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        // Mark visited numbers
        for (int i = 0; i < n; i++) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] > 0)
                nums[idx] = -nums[idx];
        }

        // Collect indices that were never marked
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                ans.push_back(i + 1);
        }

        return ans;
    }
};
