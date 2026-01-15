// Problem: Maximize Square Hole Area
// Pattern: Greedy + Observation
//
// Key Idea:
// - Removing consecutive horizontal bars creates a vertical gap
// - Removing consecutive vertical bars creates a horizontal gap
// - If we remove k consecutive bars, the resulting gap size is (k + 1)
// - The largest square hole is limited by the smaller of the two gaps
//
// Steps:
// 1. Sort the indices of removed horizontal and vertical bars
// 2. Find the longest consecutive sequence in both directions
// 3. Square side length = min(maxHorizontal, maxVertical) + 1
//
// Time Complexity: O(h log h + v log v)
// Space Complexity: O(1)

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m,
                               vector<int>& hBars,
                               vector<int>& vBars) {

        // Sort removable bars
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        // Find longest consecutive sequence in horizontal bars
        int curr = 1, maxH = 1;
        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] == hBars[i - 1] + 1)
                curr++;
            else
                curr = 1;
            maxH = max(maxH, curr);
        }

        // Find longest consecutive sequence in vertical bars
        curr = 1;
        int maxV = 1;
        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] == vBars[i - 1] + 1)
                curr++;
            else
                curr = 1;
            maxV = max(maxV, curr);
        }

        // Removing k consecutive bars gives a gap of size (k + 1)
        int side = min(maxH, maxV) + 1;

        // Area of the largest square hole
        return side * side;
    }
};
