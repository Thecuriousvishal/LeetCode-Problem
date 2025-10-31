class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_set<int> seen;
        vector<int> duplicates;

        for(int num: nums)
        {
            if(seen.count(num))
                duplicates.push_back(num);
            else
                seen.insert(num);
        }
        return duplicates;
    }
};