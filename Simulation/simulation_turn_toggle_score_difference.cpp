
// Pattern: Simulation + State Toggle
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int scoreDifference(vector<int>& nums) {

        int firstPlayerScore = 0;
        int secondPlayerScore = 0;

        // true  -> first player's turn
        // false -> second player's turn
        bool isFirstTurn = true;

        for(int i = 0; i < nums.size(); i++) {

            // Rule 1:
            // If current number is odd, toggle the turn
            if(nums[i] % 2 == 1) {
                isFirstTurn = !isFirstTurn;
            }

            // Rule 2:
            // If index (1-based) is multiple of 6, toggle the turn
            if((i + 1) % 6 == 0) {
                isFirstTurn = !isFirstTurn;
            }

            // Assign score based on whose turn it is
            if(isFirstTurn) {
                firstPlayerScore += nums[i];
            } else {
                secondPlayerScore += nums[i];
            }
        }

        // Return final score difference
        return firstPlayerScore - secondPlayerScore;
    }
};
