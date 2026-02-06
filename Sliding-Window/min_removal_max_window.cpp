#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int i = 0, maxWindow = 0;

        // Maintain largest window where max <= min * k
        for (int j = 0; j < n; j++) {
            while (1LL * nums[j] > 1LL * nums[i] * k) {
                i++;
            }
            maxWindow = max(maxWindow, j - i + 1);
        }

        return n - maxWindow;
    }
};
