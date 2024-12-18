class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Binary search in a virtual 1D array
        int left = 0;
        int right = m * n - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int mid_value = matrix[mid / n][mid % n];  // Convert 1D index back to 2D
            
            if (mid_value == target) {
                return true;
            } else if (mid_value < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return false;
    }
};