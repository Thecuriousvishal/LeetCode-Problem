class Solution {
public:
    // Map of digit to corresponding letters on a telephone keypad
    const vector<string> keypad = {
        "",    "",    "abc", "def", "ghi", "jkl", 
        "mno", "pqrs", "tuv", "wxyz"
    };
    
    // Helper function for backtracking
    void backtrack(const string& digits, string& current, vector<string>& result, int index) {
        // If all digits have been processed, add the current combination to the result
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        
        // Get the letters corresponding to the current digit
        string letters = keypad[digits[index] - '0'];
        
        // Iterate through the letters and explore each possibility
        for (char letter : letters) {
            current.push_back(letter);    // Choose the letter
            backtrack(digits, current, result, index + 1);  // Explore the next digit
            current.pop_back();           // Undo the choice (backtrack)
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};  // If the input is empty, return an empty list
        }
        
        vector<string> result;  // Stores the resulting combinations
        string current;         // Current combination being built
        backtrack(digits, current, result, 0);  // Start the backtracking process
        return result;
    }
};
