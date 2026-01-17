// Problem: Time Needed to Buy Tickets
// Pattern: Greedy / Observation
//
// Key Idea:
// - Person k needs `tickets[k]` turns
// - Everyone before or at k can buy up to `tickets[k]` tickets
// - Everyone after k can buy up to `tickets[k] - 1` tickets
// - Sum these contributions to get total time
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        int need = tickets[k];

        for (int i = 0; i < tickets.size(); i++) {
            if (i <= k) {
                time += min(tickets[i], need);
            } else {
                time += min(tickets[i], need - 1);
            }
        }
        return time;
    }
};
