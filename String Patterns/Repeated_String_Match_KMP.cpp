class Solution {
public:
    // Main function to find minimum repetitions of 'a'
    int repeatedStringMatch(string a, string b) {
        string temp = a;
        int repeat = 1;

        // Repeat 'a' until temp length >= b length
        while (temp.size() < b.size()) {
            temp += a;
            repeat++;
        }

        // Check if b is a substring using KMP
        if (kmp(b, temp)) return repeat;

        // Add one more repetition to handle overlap cases
        temp += a;
        if (kmp(b, temp)) return repeat + 1;

        return -1;
    }

    // KMP Pattern Matching Algorithm
    bool kmp(string pattern, string text) {
        int n = pattern.size();
        vector<int> lps(n, 0);

        // Build LPS array
        buildLPS(lps, pattern);

        int i = 0; // index for pattern
        int j = 0; // index for text

        while (j < text.size()) {
            if (text[j] == pattern[i]) {
                i++;
                j++;

                // Full pattern matched
                if (i == n) return true;
            } else {
                if (i != 0) {
                    i = lps[i - 1];
                } else {
                    j++;
                }
            }
        }
        return false;
    }

    // Function to build LPS (Longest Prefix Suffix) array
    void buildLPS(vector<int>& lps, string pattern) {
        int len = 0; // length of previous longest prefix suffix
        int i = 1;

        while (i < pattern.size()) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
};
