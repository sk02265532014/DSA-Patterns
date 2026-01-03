// Problem: Climbing Stairs
// Pattern: Dynamic Programming (Fibonacci / Space Optimized)
// Key idea: ways(n) = ways(n-1) + ways(n-2)
class Solution {
public:
    int climbStairs(int n) {
        int f1=1;
        int f2=1;

        if(n==1) return 1;
        int f3;
        
        for(int i=2;i<=n;i++){
            f3=f1+f2;
            f2=f1;
            f1=f3;
        }
        return f1;
    }
};
