class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> elements;

        for(int i=0;i<nums.size();i++){
            if(elements.find(nums[i])!=elements.end()){
                return true;
            }
            elements.insert(nums[i]);
        }
        return false;
    }
};