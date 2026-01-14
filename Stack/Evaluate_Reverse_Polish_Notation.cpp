// Evaluate Reverse Polish Notation
// Category: Stack / Simulation
//
// Idea:
// - Use a stack to store operands
// - When an operator is encountered:
//   - Pop two operands
//   - Apply the operator
//   - Push the result back
//
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();

                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else st.push(a / b);
            }
            else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};
