/*
    Pattern: KMP (Longest Prefix Suffix - LPS Array)

    Problem:
    Given a string, compute the length of the longest proper prefix
    which is also a suffix.

    Time Complexity: O(n)
    Space Complexity: O(n)

    Key Idea:
    - Use previously computed LPS values to avoid re-checking characters
    - On mismatch, fall back using lps[previous_length - 1]
*/

class Solution {
public:
    int getLPSLength(string &s) {
        int n = s.length();

        // lps[i] stores the length of the longest prefix
        // which is also a suffix for substring s[0..i]
        vector<int> lps(n, 0);

        int prefixLen = 0;   // length of current matching prefix
        int currIndex = 1;   // current index being processed

        while (currIndex < n) {

            // Case 1: characters match → extend prefix
            if (s[prefixLen] == s[currIndex]) {
                prefixLen++;
                lps[currIndex] = prefixLen;
                currIndex++;
            }
            // Case 2: mismatch after some matches
            else {
                if (prefixLen != 0) {
                    // Fall back to previous longest prefix
                    prefixLen = lps[prefixLen - 1];
                } else {
                    // No prefix matched
                    lps[currIndex] = 0;
                    currIndex++;
                }
            }
        }

        // Last value of LPS array gives the answer
        return lps[n - 1];
    }
};
