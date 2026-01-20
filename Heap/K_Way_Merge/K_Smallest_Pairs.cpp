// Problem: Find K Pairs with Smallest Sums
// Pattern: Min Heap + K-way Merge
//
// Key Idea:
// - Treat each nums1[i] + nums2[j] as a state (i, j)
// - Initially push pairs (i, 0) for i < k
// - Always expand the next pair (i, j + 1)
// - This avoids generating all possible pairs
//
// Time Complexity: O(k log k)
// Space Complexity: O(k)

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1,
                                       vector<int>& nums2,
                                       int k) {

        vector<vector<int>> ans;

        if (nums1.empty() || nums2.empty() || k == 0)
            return ans;

        // Min heap storing (sum, index in nums1, index in nums2)
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        // Push first k pairs (nums1[i], nums2[0])
        for (int i = 0; i < nums1.size() && i < k; i++) {
            pq.push({nums1[i] + nums2[0], i, 0});
        }

        // Extract k smallest pairs
        while (!pq.empty() && k--) {
            auto [sum, i, j] = pq.top();
            pq.pop();

            ans.push_back({nums1[i], nums2[j]});

            // Push next pair in the row
            if (j + 1 < nums2.size()) {
                pq.push({nums1[i] + nums2[j + 1], i, j + 1});
            }
        }

        return ans;
    }
};
