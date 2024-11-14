class Solution {
public:
    int calculate(string s) {
        std::stack<int> stk;
        int result = 0; // Stores the final evaluated result
        int sign = 1;   // Current sign: +1 for positive, -1 for negative
        int i = 0;      // Pointer to traverse the string
        int n = s.length();

        while (i < n) {
            char ch = s[i];

            if (isdigit(ch)) {
                // Form the full number in case of multiple digits
                int num = 0;
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                result += sign * num; // Add the number to the result with the current sign
                i--; // Adjust index because for loop will increment it again
            } else if (ch == '+') {
                sign = 1; // Set sign to positive
            } else if (ch == '-') {
                sign = -1; // Set sign to negative
            } else if (ch == '(') {
                // Push the current result and sign onto the stack
                stk.push(result);
                stk.push(sign);
                // Reset result and sign for a new sub-expression
                result = 0;
                sign = 1;
            } else if (ch == ')') {
                // Finalize the expression inside parentheses
                result = stk.top() * result; // Multiply by sign before parentheses
                stk.pop();
                result += stk.top(); // Add result before parentheses
                stk.pop();
            }
            i++;
        }

        return result;
    }
};