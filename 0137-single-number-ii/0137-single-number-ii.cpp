class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int ones = 0, twos = 0;
        
        for (int num : nums) {
            // Update `ones` with bits that have appeared once
            ones = (ones ^ num) & ~twos;
            
            // Update `twos` with bits that have appeared twice
            twos = (twos ^ num) & ~ones;
        }
        
        // `ones` holds the unique element that appears only once
        return ones;
    }
};