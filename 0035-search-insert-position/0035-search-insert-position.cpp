class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
    
        while (left <= right) {
            int mid = left + (right - left) / 2;  // Calculate mid to avoid overflow

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;  // Search the right half
            } else {
                right = mid - 1;  // Search the left half
            }
        }

        return left;  // Target not found, return the insertion position
    }
};