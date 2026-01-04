// Problem: Product of Array Except Self
// Pattern: Prefix & Suffix Product
// Key Idea:
// answer[i] = product of all elements before i
//             × product of all elements after i
// Time Complexity: O(n)
// Space Complexity: O(1) extra space (excluding output array)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        // Prefix products
        for(int i = 1; i < n; i++) {
            ans[i] = nums[i - 1] * ans[i - 1];
        }

        // Suffix products
        int right = 1;
        for(int i = n - 2; i >= 0; i--) {
            right *= nums[i + 1];
            ans[i] *= right;
        }

        return ans;
    }
};
