class Solution {
public:
    void backtrack(int start, vector<int>& nums, vector<int>& currentSubset, vector<vector<int>>&         result) {
        // Add the current subset to the result
        result.push_back(currentSubset);
        
        for (int i = start; i < nums.size(); i++) {
            // Include nums[i] in the current subset
            currentSubset.push_back(nums[i]);
            // Recurse with the next element
            backtrack(i + 1, nums, currentSubset, result);
            // Backtrack by removing nums[i] from the current subset
            currentSubset.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentSubset;
        backtrack(0, nums, currentSubset, result);
        return result;
    }
};