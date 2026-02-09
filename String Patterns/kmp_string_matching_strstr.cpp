/*
    Pattern: KMP (Knuth-Morris-Pratt) String Matching

    Problem:
    Find the first occurrence of 'needle' in 'haystack'.

    Approach:
    - Preprocess the pattern (needle) using LPS array
    - Use LPS to avoid redundant comparisons on mismatch

    Time Complexity: O(m + n)
    Space Complexity: O(n)
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int textLen = haystack.size();
        int patLen  = needle.size();

        if (patLen == 0) return 0;

        // Build LPS array for the pattern
        vector<int> lps(patLen, 0);
        buildLPS(lps, needle);

        int textIdx = 0;   // index for haystack
        int patIdx  = 0;   // index for needle

        while (textIdx < textLen) {

            // Characters match → move both pointers
            if (haystack[textIdx] == needle[patIdx]) {
                textIdx++;
                patIdx++;
            }

            // Full pattern matched
            if (patIdx == patLen) {
                return textIdx - patIdx;
            }
            // Mismatch after some matches
            else if (textIdx < textLen && haystack[textIdx] != needle[patIdx]) {
                if (patIdx == 0) {
                    textIdx++;   // no prefix matched, move text pointer
                } else {
                    patIdx = lps[patIdx - 1];  // fallback using LPS
                }
            }
        }

        return -1;
    }

private:
    // Builds the Longest Prefix Suffix (LPS) array
    void buildLPS(vector<int>& lps, string& pattern) {
        int prefixLen = 0;   // length of previous longest prefix
        int i = 1;

        while (i < pattern.size()) {
            if (pattern[i] == pattern[prefixLen]) {
                prefixLen++;
                lps[i] = prefixLen;
                i++;
            } else {
                if (prefixLen == 0) {
                    lps[i] = 0;
                    i++;
                } else {
                    prefixLen = lps[prefixLen - 1];
                }
            }
        }
    }
};
