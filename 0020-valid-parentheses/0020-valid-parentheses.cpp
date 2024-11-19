class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> st; // Stack to store opening brackets
        for (char ch : s)
        {
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch); // Push opening brackets onto the stack
            } else {
                // If stack is empty or top doesn't match the closing bracket
                if (st.empty() || 
                (ch == ')' && st.top() != '(') || 
                (ch == ']' && st.top() != '[') || 
                (ch == '}' && st.top() != '{')) {
                    return false;
                }
                st.pop(); // Pop matching opening bracket
            }
        }
        return st.empty(); // If stack is empty, string is valid
    }
};