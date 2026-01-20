// Problem: Construct Target Array With Multiple Sums
// Pattern: Greedy + Max Heap + Mathematical Reduction
//
// Key Idea:
// - Work backwards from the target array
// - At each step, reduce the largest element
// - Instead of subtracting repeatedly, use modulo
// - Maintain total sum to compute the "rest"
//
// Time Complexity: O(n log n)
// Space Complexity: O(n)

class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long sum = 0;
        priority_queue<long long> pq;

        // Initialize heap and total sum
        for (int x : target) {
            sum += x;
            pq.push(x);
        }

        while (true) {
            long long mx = pq.top();
            pq.pop();

            long long rest = sum - mx;

            // Base cases
            if (mx == 1 || rest == 1)
                return true;

            // Invalid cases
            if (rest == 0 || rest >= mx)
                return false;

            // Reduce the largest element
            long long prev = mx % rest;

            if (prev == 0)
                return false;

            // Update sum and heap
            sum = rest + prev;
            pq.push(prev);
        }
    }
};
