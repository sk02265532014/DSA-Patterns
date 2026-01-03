// Problem: Number of Ways to Paint N x 3 Grid
// Pattern: State Compression DP
// Key idea: Each row has only 2 valid color patterns
class Solution {
public:
    int numOfWays(int n) {
        int mod = 1e9 + 7;
        long long diff = 6, same = 6;

        for(int i = 1; i < n; i++) {
            long long s = (3*same + 2*diff)%mod;
            long long d = (2*same + 2*diff)%mod;

            same = s;
            diff = d; 
        }

        return (same + diff)%mod;
    }
};
