class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int left = j + 1, right = nums.size() - 1;
                while (left < right) {
                    // Use long long for summing to avoid overflow
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[left] + (long long)nums[right];
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        left++;
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
                while (j + 1 < nums.size() && nums[j] == nums[j + 1]) j++;
            }
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
        }
        return result;
    }
};
