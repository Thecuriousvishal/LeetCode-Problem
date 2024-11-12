class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (backtrack(board, word, i, j, 0)) 
                {
                    return true;
                }
            }
        }
        return false;
    }


private:
    bool backtrack(vector<vector<char>>& board, const string& word, int i, int j, int index) 
    {
        // If we have matched all characters in the word
        if (index == word.length()) return true;
        
        // Check if we are out of bounds or the character doesn't match
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) {
            return false;
        }
        
        // Mark this cell as visited
        char temp = board[i][j];
        board[i][j] = '#';
        
        // Explore in all four possible directions
        bool found = backtrack(board, word, i + 1, j, index + 1) ||  // Down
                     backtrack(board, word, i - 1, j, index + 1) ||  // Up
                     backtrack(board, word, i, j + 1, index + 1) ||  // Right
                     backtrack(board, word, i, j - 1, index + 1);    // Left
        
        // Restore the cell's original value after exploring
        board[i][j] = temp;
        
        return found;
    }
};