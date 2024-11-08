class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;  // No primes less than 2

        std::vector<bool> is_prime(n, true);  // Boolean array for prime marking
        is_prime[0] = is_prime[1] = false;    // 0 and 1 are not prime numbers

        // Sieve of Eratosthenes
        for (int i = 2; i * i < n; ++i) {
            if (is_prime[i]) {  // If `i` is a prime number
                for (int j = i * i; j < n; j += i) {
                    is_prime[j] = false;  // Mark multiples of `i` as non-prime 
                }
            }
        }
        // Count the number of primes
        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (is_prime[i]) ++count;
        }
        return count;
    }
};