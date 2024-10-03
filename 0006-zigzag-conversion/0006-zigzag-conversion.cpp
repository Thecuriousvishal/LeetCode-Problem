class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) {
        return s;
    }

    vector<string> rows(min(numRows, static_cast<int>(s.size())));
    int curRow = 0;
    bool goingDown = false; 

    for (char c : s) {
        rows[curRow] += c; 
        
        if (curRow == 0) {
            goingDown = true; 
        } else if (curRow == numRows - 1) {
            goingDown = false; 
        }
        curRow += goingDown ? 1 : -1;
    }
    
    string result;
    for (const std::string& row : rows) {
        result += row;
    }
    return result; 
    }
};