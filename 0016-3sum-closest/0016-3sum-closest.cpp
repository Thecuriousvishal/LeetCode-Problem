class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
    sort(nums.begin(), nums.end());
    int closestSum = INT_MAX;
    int minDiff = INT_MAX;

    for (int i = 0; i < n - 2; ++i) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            int diff = abs(sum - target);

            if (diff < minDiff) {
                minDiff = diff;
                closestSum = sum;
            }

            if (sum < target) {
                ++left;
            } else if (sum > target) {
                --right;
            } else {
                return sum; // Found an exact match, no need to continue
            }
        }
    }

    return closestSum;
    }
};