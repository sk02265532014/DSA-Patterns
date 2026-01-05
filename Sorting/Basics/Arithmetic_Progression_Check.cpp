// Problem: Check Arithmetic Progression
// Pattern: Sorting + Difference Check
// Key Idea: After sorting, all consecutive differences must be equal
// Time Complexity: O(n log n)
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());

        int d=arr[1]-arr[0];
        for(int i=2;i<arr.size();i++){
            if(arr[i]-arr[i-1]!=d) return false;
        }
        return true;
    }
};
