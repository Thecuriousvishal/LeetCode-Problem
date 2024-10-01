class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length();
        long result = 0;
        int sign = 1;

        // Step 1: Ignore leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Step 2: Handle optional sign
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Convert digits to an integer
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            // Step 4: Handle overflow
            if (sign * result <= INT_MIN) {
                return INT_MIN;
            }
            if (sign * result >= INT_MAX) {
                return INT_MAX;
            }

            i++;
        }

        // Step 5: Return final result
        return sign * result;
    }
};