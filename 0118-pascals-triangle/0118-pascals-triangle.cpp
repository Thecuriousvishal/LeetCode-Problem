class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> triangle;

        // Loop to generate each row
        for (int i = 0; i < numRows; ++i) {
            // Start a new row with size (i + 1), and initialize all elements to 1
            vector<int> row(i + 1, 1);

            // Calculate the values for inner elements of the row
            for (int j = 1; j < i; ++j) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }

            // Add the row to the triangle
            triangle.push_back(row);
        }

        return triangle;
    }
};