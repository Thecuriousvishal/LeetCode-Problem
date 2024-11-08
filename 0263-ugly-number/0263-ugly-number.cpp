class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;  // Ugly numbers are positive

        // Divide `n` by 2, 3, and 5 as long as possible
        while (n % 2 == 0) n /= 2;
        while (n % 3 == 0) n /= 3;
        while (n % 5 == 0) n /= 5;

         // If n becomes 1, it means n was only composed of prime factors 2, 3, and 5
        return n == 1;
        }
       
};