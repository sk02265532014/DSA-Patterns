/*
Problem: Generate Parentheses (LeetCode 22)

Pattern: Backtracking

Description:
Given n pairs of parentheses, generate all possible combinations
of well-formed (balanced) parentheses.

Key Idea:
We build the string step-by-step using recursion.

Two constraints ensure the string always stays valid:

1. We can add '(' only if we still have opening brackets left
   open < n

2. We can add ')' only if there are unmatched '('
   close < open

This guarantees that we never produce invalid sequences.

Example:
n = 3

Output:
((()))
(()())
(())()
()(())
()()()

Time Complexity:
O(4^n / sqrt(n))  → number of valid parentheses combinations
(Catalan numbers)

Space Complexity:
O(n) → recursion stack depth
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    // Backtracking function to build parentheses combinations
    void backtrack(int open, int close, int n, string current, vector<string>& result) {

        // If the current string length reaches 2*n, we formed a valid combination
        if(current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Add '(' if we still have opening brackets available
        if(open < n) {
            backtrack(open + 1, close, n, current + "(", result);
        }

        // Add ')' only if it keeps the string valid
        if(close < open) {
            backtrack(open, close + 1, n, current + ")", result);
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> result;

        // Start recursion with 0 open and 0 close brackets
        backtrack(0, 0, n, "", result);

        return result;
    }
};
