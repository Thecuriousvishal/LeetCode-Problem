class Solution {
public:
    int fib(int n) {
         // Base cases
        if (n == 0) return 0;
        if (n == 1) return 1;

        // Iterative calculation
        int prev1 = 0; // F(0)
        int prev2 = 1; // F(1)
        int curr;      // To store F(n)

        for (int i = 2; i <= n; i++) {
            curr = prev1 + prev2; // F(i) = F(i-1) + F(i-2)
            prev1 = prev2;        // Update prev1 to F(i-1)
            prev2 = curr;         // Update prev2 to F(i)
        }

        return curr; // Return F(n)
    }
};