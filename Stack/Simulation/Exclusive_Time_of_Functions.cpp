// Problem: Exclusive Time of Functions
// Pattern: Stack + Simulation
//
// Key Idea:
// - Use a stack to track active function calls
// - Maintain prevTime to correctly calculate exclusive execution time
// - When a function starts, pause the previous function
// - When a function ends, finalize its execution time
//
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> st;                 // stack of function IDs
        vector<int> ans(n, 0);         // exclusive time for each function
        int prevTime = 0;              // last processed timestamp

        for (string& log : logs) {
            int id, time;
            string type;

            parseLog(log, id, time, type);

            if (type == "start") {
                // Pause currently running function
                if (!st.empty()) {
                    ans[st.top()] += time - prevTime;
                }
                st.push(id);
                prevTime = time;
            } 
            else { // "end"
                // Finish current function
                ans[st.top()] += time - prevTime + 1;
                st.pop();
                prevTime = time + 1;
            }
        }

        return ans;
    }

private:
    // Parse log string into id, type, and timestamp
    void parseLog(const string& log, int& id, int& time, string& type) {
        int i = 0;
        id = 0;

        // Parse function id
        while (log[i] != ':') {
            id = id * 10 + (log[i] - '0');
            i++;
        }
        i++;

        // Parse type ("start" or "end")
        int start = i;
        while (log[i] != ':') i++;
        type = log.substr(start, i - start);

        // Parse timestamp
        time = 0;
        i++;
        while (i < log.size()) {
            time = time * 10 + (log[i] - '0');
            i++;
        }
    }
};
