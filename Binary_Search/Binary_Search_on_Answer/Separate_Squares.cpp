// Problem: Separate Squares
// Pattern: Binary Search on Answer + Geometry
//
// Key Idea:
// - We need to find a horizontal line Y such that
//   total area below the line == total area above the line
// - The area difference function is monotonic with respect to Y
// - Use binary search on Y in continuous space
//
// Approach:
// 1. Binary search the Y-coordinate
// 2. For a given Y, compute:
//    - area below Y
//    - area above Y
// 3. Adjust search range based on area difference
//
// Time Complexity: O(n * log precision)
// Space Complexity: O(1)

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e18, high = -1e18;

        // Determine search range for Y
        for (auto& s : squares) {
            low = min(low, (double)s[1]);
            high = max(high, (double)(s[1] + s[2]));
        }

        // Binary search for the balancing Y-coordinate
        for (int i = 0; i < 60; i++) { // sufficient for double precision
            double mid = (low + high) / 2.0;

            if (areaDiff(mid, squares) < 0)
                low = mid;
            else
                high = mid;
        }

        return (low + high) / 2.0;
    }

private:
    // Returns (area below Y) - (area above Y)
    double areaDiff(double Y, vector<vector<int>>& squares) {
        double below = 0.0, above = 0.0;

        for (auto& s : squares) {
            double y = s[1];      // bottom Y of square
            double len = s[2];    // side length
            double top = y + len;
            double area = len * len;

            if (Y <= y) {
                // Entire square is above the line
                above += area;
            } else if (Y >= top) {
                // Entire square is below the line
                below += area;
            } else {
                // Line cuts the square
                below += len * (Y - y);
                above += len * (top - Y);
            }
        }
        return below - above;
    }
};
