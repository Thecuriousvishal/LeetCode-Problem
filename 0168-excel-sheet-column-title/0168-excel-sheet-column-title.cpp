class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result;
        while (columnNumber > 0) {
            columnNumber--; // Adjust columnNumber for 0-indexed
            int remainder = columnNumber % 26;
            result += (remainder + 'A');
            columnNumber /= 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};