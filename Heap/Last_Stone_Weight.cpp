// Problem: Last Stone Weight
// Category: Heap / Simulation
//
// Idea:
// - Use a max heap to always take the two heaviest stones
// - Smash them and push the remaining weight (if any) back
//
// Time Complexity: O(n log n)
// Space Complexity: O(n)

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        // Push all stones into max heap
        for (int x : stones)
            maxHeap.push(x);

        // Smash stones until at most one remains
        while (maxHeap.size() > 1) {
            int a = maxHeap.top(); maxHeap.pop();
            int b = maxHeap.top(); maxHeap.pop();

            if (a != b)
                maxHeap.push(a - b);
        }

        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
