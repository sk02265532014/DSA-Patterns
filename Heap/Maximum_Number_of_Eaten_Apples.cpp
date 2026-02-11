/*
    Problem: Maximum Number of Eaten Apples
    Approach: Greedy + Min Heap

    Idea:
    - Each day, add newly grown apples with their expiry day.
    - Always eat the apple that expires the earliest.
    - Remove all expired apples before eating.
    - Continue even after day 'n' until no apples are left.

    Time Complexity: O(n log n)
    Space Complexity: O(n)
*/

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {

        // Min-heap storing {expiry_day, count_of_apples}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        int n = apples.size();
        int day = 0;
        int eaten = 0;

        // Continue while days are left or heap still has apples
        while(day < n || !pq.empty()) {

            // Add today's apples to the heap
            if(day < n && apples[day] > 0) {
                pq.push({day + days[day], apples[day]});
            }

            // Remove expired apples
            while(!pq.empty() && pq.top().first <= day) {
                pq.pop();
            }

            // Eat one apple with the earliest expiry
            if(!pq.empty()) {
                auto curr = pq.top();
                pq.pop();

                curr.second--;
                eaten++;

                // If apples still remain, push back
                if(curr.second > 0) {
                    pq.push(curr);
                }
            }

            // Move to next day
            day++;
        }

        return eaten;
    }
};
