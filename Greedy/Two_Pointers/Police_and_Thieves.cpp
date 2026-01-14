// Police and Thieves
// Pattern: Greedy + Two Pointers
//
// Idea:
// - Store positions of policemen and thieves separately
// - Use two pointers to greedily match the closest valid pairs
// - Each policeman and thief can be used only once
//
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int catchThieves(vector<char>& arr, int k) {
        vector<int> police, thieves;

        // Collect positions of policemen and thieves
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 'P')
                police.push_back(i);
            else if (arr[i] == 'T')
                thieves.push_back(i);
        }

        int i = 0, j = 0;
        int caught = 0;

        // Greedy matching using two pointers
        while (i < police.size() && j < thieves.size()) {
            if (abs(police[i] - thieves[j]) <= k) {
                // Valid match
                caught++;
                i++;
                j++;
            }
            else if (thieves[j] < police[i]) {
                // Thief is too far left, move thief pointer
                j++;
            }
            else {
                // Policeman is too far left, move police pointer
                i++;
            }
        }

        return caught;
    }
};
