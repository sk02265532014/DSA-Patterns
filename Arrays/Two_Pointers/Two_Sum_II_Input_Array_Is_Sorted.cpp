/*
Problem:
Given a sorted array of integers, find two numbers such that they add up to a
specific target number.

Return the indices of the two numbers (1-indexed).

Approach:
- Use two pointers:
  - Left pointer starts at beginning
  - Right pointer starts at end
- If sum is too large → move right pointer left
- If sum is too small → move left pointer right

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int i = 0;                      // Left pointer
        int j = numbers.size() - 1;     // Right pointer

        // Traverse the array using two pointers
        while (i < j) {
            int currentSum = numbers[i] + numbers[j];

            // If target is found, return 1-based indices
            if (currentSum == target) {
                return {i + 1, j + 1};
            }
            // If sum is greater than target, decrease right pointer
            else if (currentSum > target) {
                j--;
            }
            // If sum is smaller than target, increase left pointer
            else {
                i++;
            }
        }

        // No valid pair found
        return {};
    }
};
