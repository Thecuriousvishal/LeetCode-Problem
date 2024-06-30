class Solution {
public:
    int climbStairs(int n) {
        if(n<0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        
        int prev1 = 1; // ways to reach step 1
        int prev2 = 2; // ways to reach step 2
        int current = 0;

        for (int i = 3; i <= n; ++i) {
            current = prev1 + prev2;
            prev1 = prev2;
            prev2 = current;
        }

        return current;
    }
};