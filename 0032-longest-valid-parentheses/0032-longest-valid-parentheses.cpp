class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);  // Initial base for valid substring
        int maxLength = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                // Push the index of the '(' onto the stack
                st.push(i);
            } else {
                // Pop the last unmatched '('
                st.pop();
                if (st.empty()) {
                    // If stack is empty, push the current index as the base
                    st.push(i);
                } else {
                    // Calculate the length of the valid substring
                    int currentLength = i - st.top();
                    maxLength = max(maxLength, currentLength);
                }
            }
        }
        return maxLength;
    }
};