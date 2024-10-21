class Solution {
public:
    void backtrack(string current, int openCount, int closeCount, int maxPairs, vector<string>& result) {
        // If the current string has reached the maximum length (2 * n), add it to the result
        if (current.length() == 2 * maxPairs) {
            result.push_back(current);
            return;
        }

        // If we can still add an open parenthesis, add it
        if (openCount < maxPairs) {
            backtrack(current + "(", openCount + 1, closeCount, maxPairs, result);
        }

        // If we can add a closing parenthesis without breaking the validity, add it
        if (closeCount < openCount) {
            backtrack(current + ")", openCount, closeCount + 1, maxPairs, result);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack("", 0, 0, n, result);  // Start backtracking with empty string and zero counts
        return result;
    }
};
