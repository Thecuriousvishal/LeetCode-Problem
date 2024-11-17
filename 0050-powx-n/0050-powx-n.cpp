class Solution {
public:
    double myPow(double x, int n) {
        // Handle negative exponents
        long long N = n; // Use long long to avoid overflow when n is INT_MIN
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double result = 1.0;
        double currentProduct = x;

        // Iterative exponentiation by squaring
        while (N > 0) {
            if (N % 2 == 1) { // If N is odd
                result *= currentProduct;
            }
            currentProduct *= currentProduct; // Square the base
            N /= 2; // Halve the exponent
        }

        return result;

    }
};