/*
    Problem: First Element with Unique Frequency
    Platform: LeetCode
    Difficulty: Medium

    Description:
    Given an integer array nums, return the first element (from left to right)
    whose frequency is unique (no other element appears the same number of times).
    If no such element exists, return -1.

    Approach:
    1. Count frequency of each element.
    2. Count how many elements share the same frequency.
    3. Traverse the array again and return the first element
       whose frequency occurs exactly once.

    Time Complexity: O(N)
    Space Complexity: O(N)
*/

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {

        // Step 1: Count frequency of each element
        unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }

        // Step 2: Count frequency of frequencies
        unordered_map<int, int> freqCount;
        for (auto &p : freq) {
            freqCount[p.second]++;
        }

        // Step 3: Find first element with unique frequency
        for (int x : nums) {
            if (freqCount[freq[x]] == 1) {
                return x;
            }
        }

        return -1;
    }
};
