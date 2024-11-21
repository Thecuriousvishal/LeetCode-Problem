class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        // Step 1: Find the maximum candies any child currently has
        int maxCandies = *std::max_element(candies.begin(), candies.end());

        // Step 2: Prepare the result vector
        std::vector<bool> result;

        // Step 3: Check for each child if they can have the greatest candies
        for (int candy : candies) {
            result.push_back(candy + extraCandies >= maxCandies);
        }
        return result;
    }
};