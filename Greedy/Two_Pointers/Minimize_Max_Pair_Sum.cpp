// Problem: Minimize Maximum Pair Sum in Array
// Category: Greedy + Two Pointers
//
// Key Idea:
// - Sort the array
// - Pair smallest with largest
// - Track the maximum pair sum
//
// Time Complexity: O(n log n)
// Space Complexity: O(1)

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int i = 0, j = nums.size() - 1;
        int ans = INT_MIN;

        while (i < j) {
            ans = max(ans, nums[i] + nums[j]);
            i++;
            j--;
        }
        return ans;
    }
};
