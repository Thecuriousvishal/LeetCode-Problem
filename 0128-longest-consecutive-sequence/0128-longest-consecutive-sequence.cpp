class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Edge case: if the array is empty
        if (nums.empty()) {
            return 0;
        }

        // Use an unordered_set for O(1) average time complexity on lookups
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longestStreak = 0;

        // Iterate through the set
        for (int num : numSet) {
            // Only consider the start of a sequence
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;

                // Find the consecutive numbers in the sequence
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentStreak++;
                }

                // Update the longest streak found
                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};