class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow for edge case
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        if (dividend == divisor) return 1;

        bool sign = true;
        if (dividend >= 0 && divisor < 0) {
            sign = false;
        } else if (dividend <= 0 && divisor > 0) {
            sign = false;
        }

        long n = abs(static_cast<long>(dividend));
        long d = abs(static_cast<long>(divisor));
        long quotient = 0;
        while (n >= d) {
            int cnt = 0;
            while (n >= (d << (cnt + 1))) {
                cnt += 1;
            }
            quotient += 1 << cnt;
            n -= (d << cnt);
        }

        return sign ? quotient : -quotient;
    }
};
