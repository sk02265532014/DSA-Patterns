/*
Problem: LeetCode 1980 - Find Unique Binary String

Idea:
Use Cantor's Diagonalization.

Flip the ith bit of nums[i] to construct a new string.
This guarantees the new string differs from every
string in nums at least at one position.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;
        for(int i=0;i<nums.size();i++)
            ans += (nums[i][i]=='0') ? '1' : '0';
        return ans;
    }
};
