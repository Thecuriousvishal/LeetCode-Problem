class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        // Create sets for rows, columns, and boxes
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> colms(9);
        vector<unordered_set<char>> boxes(9);
        
        
        //Iterate through each cell in a board
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char num=board[i][j];
                
                if(num!='.'){
                    // Determine which box we are in
                    int boxIndex=(i/3)*3 + (j/3);
                    
                    // Check for duplicates in row, column and box
                    if(rows[i].count(num) || colms[j].count(num) || boxes[boxIndex].count(num)){
                        return false;
                    }
                    
                    // Add the number to the corresponding sets
                    rows[i].insert(num);
                    colms[j].insert(num);
                    boxes[boxIndex].insert(num);
                }
            }
        }
        return true;
    }
};