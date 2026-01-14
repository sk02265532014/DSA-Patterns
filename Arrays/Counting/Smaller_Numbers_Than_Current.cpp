// Smaller Numbers Than Current
// Category: Array / Counting
//
// Idea:
// - Since numbers are in range [0, 100], use a frequency array
// - Build prefix sum to know how many numbers are smaller
//
// Time Complexity: O(n + k), where k = 101
// Space Complexity: O(k)

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();

        // Frequency array for numbers [0..100]
        vector<int> freq(101, 0);

        for (int x : nums)
            freq[x]++;

        // Prefix sum to count numbers <= i
        for (int i = 1; i <= 100; i++)
            freq[i] += freq[i - 1];

        // Replace each element with count of smaller numbers
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                nums[i] = 0;
            else
                nums[i] = freq[nums[i] - 1];
        }

        return nums;
    }
};
