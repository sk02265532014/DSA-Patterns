// Problem: Redundant Brackets
// Pattern: Stack + Expression Parsing
//
// Key Idea:
// - Use a stack to process characters
// - When a closing bracket ')' is found:
//   - Check if there is at least one operator inside the brackets
//   - If no operator exists, brackets are redundant
//
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    bool checkRedundancy(string& s) {
        stack<char> st;

        for (char ch : s) {
            // Push all characters except ')'
            if (ch != ')') {
                st.push(ch);
            } 
            else {
                bool hasOperator = false;

                // Pop until '(' is found
                while (!st.empty() && st.top() != '(') {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                        hasOperator = true;
                    st.pop();
                }

                // Remove '('
                st.pop();

                // If no operator was found, brackets are redundant
                if (!hasOperator)
                    return true;
            }
        }
        return false;
    }
};
