/*
------------------------------------------------------------
Problem: Find K-th Bit in N-th Binary String
Platform: LeetCode (1545)
Approach: Recursive Divide & Conquer
------------------------------------------------------------

Definition:
S1 = "0"
Sn = S(n-1) + "1" + reverse(invert(S(n-1)))

Observations:
1. Length of Sn = 2^n - 1
2. Middle index = 2^(n-1)
3. Structure:
   Left  -> S(n-1)
   Mid   -> '1'
   Right -> reverse(invert(S(n-1)))

Logic:
- If k == middle → return '1'
- If k < middle → recurse in left half
- If k > middle → mirror to left half and invert result

Time Complexity: O(n)
Space Complexity: O(n) (recursion stack)

------------------------------------------------------------
*/

class Solution {
public:
    char findKthBit(int n, int k) {

        // Base case:
        // For n = 1, string is "0"
        if (n == 1) 
            return '0';

        // Length of current string: 2^n - 1
        int len = (1 << n) - 1;

        // Middle position: 2^(n-1)
        int mid = (len + 1) / 2;

        // If k is exactly the middle element
        if (k == mid) 
            return '1';

        // If k lies in the left half
        if (k < mid) 
            return findKthBit(n - 1, k);

        // If k lies in the right half:
        // Map it to mirrored position in left half
        char bit = findKthBit(n - 1, len - k + 1);

        // Since right half is inverted,
        // we invert the result
        return (bit == '0') ? '1' : '0';
    }
};
