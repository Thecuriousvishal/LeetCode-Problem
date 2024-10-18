class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        //step 1: Place elements in their correct position(If possible)
        for(int i=0; i<n;i++){
            while(nums[i]>0 && nums[i] <=n && nums[nums[i]-1]!=nums[i]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }

        // step 2: Find the first missing positive integer
        for(int i=0; i<n;i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }

        //If all positions are correct, the missing number is n+1
        return n+1;

    }
};