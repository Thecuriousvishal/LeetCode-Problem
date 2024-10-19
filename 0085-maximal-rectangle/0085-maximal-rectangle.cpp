class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxArea = 0;

        // Process each row
        for (int i = 0; i < rows; ++i) {
            // Update the heights of histogram bars
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    heights[j] += 1; // increase the height
                } else {
                    heights[j] = 0; // reset the height
                }
            }
            // Calculate the largest rectangle area for this row's histogram
            maxArea = max(maxArea, largestRectangleInHistogram(heights));
        }
        return maxArea;
    }

private:
    // Helper function to calculate the largest rectangle in a histogram
    int largestRectangleInHistogram(const vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; ++i) {
            int h = (i == n ? 0 : heights[i]);
            while (!st.empty() && h < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        return maxArea;
    }
};