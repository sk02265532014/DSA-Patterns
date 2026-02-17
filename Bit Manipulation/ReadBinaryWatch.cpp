/*
    Problem: Read Binary Watch
    Platform: LeetCode
    Topic: Bit Manipulation
    Difficulty: Easy

    Approach:
    1. Iterate through all possible valid hours (0–11) and minutes (0–59).
    2. Count total set bits (1s) in hour and minute.
    3. If total set bits == turnedOn, add formatted time to result.

    Optimization:
    - Use Brian Kernighan’s Algorithm to count set bits efficiently.
    - Time Complexity: O(12 * 60 * k)
      where k = number of set bits (very small here).
*/

class Solution {
public:

    /*
        Function: countBits
        Purpose : Count number of set bits (1s) in integer x
        Method  : Brian Kernighan’s Algorithm
        Idea    : Each iteration removes the lowest set bit
                  using x = x & (x - 1)
        Time Complexity: O(number of set bits)
    */
    int countBits(int x) {
        int ans = 0;

        while (x > 0) {
            x = x & (x - 1);  // remove lowest set bit
            ans++;
        }

        return ans;
    }

    /*
        Function: readBinaryWatch
        Purpose : Return all possible times where total LEDs ON == turnedOn
    */
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;

        // Iterate through all valid hours and minutes
        for (int hour = 0; hour < 12; hour++) {
            for (int minute = 0; minute < 60; minute++) {

                // If total set bits match turnedOn
                if (countBits(hour) + countBits(minute) == turnedOn) {

                    // Format minute to always have 2 digits
                    ans.push_back(
                        to_string(hour) + ":" +
                        (minute < 10 ? "0" : "") +
                        to_string(minute)
                    );
                }
            }
        }

        return ans;
    }
};
