
// Problem: Repeatedly split the string into groups of size k,
// sum digits of each group, and form a new string until length <= k.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string digitSum(string s, int k) {

        // Repeat the process until string length becomes <= k
        while (s.length() > k) {
            string result = "";

            // Process the string in chunks of size k
            for (int i = 0; i < s.length(); i += k) {

                int sum = 0;

                // Compute sum of current chunk
                for (int j = i; j < min(i + k, (int)s.length()); j++) {
                    sum += s[j] - '0';
                }

                // Append the sum to result string
                result += to_string(sum);
            }

            // Update string for next iteration
            s = result;
        }

        return s;
    }
};
