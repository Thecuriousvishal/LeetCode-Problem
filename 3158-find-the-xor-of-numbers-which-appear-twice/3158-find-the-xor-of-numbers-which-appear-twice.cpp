class Solution {
public:
    int duplicateNumbersXOR(std::vector<int>& nums) 
    {
        std::unordered_map<int, int> frequency;
        
        // Count the frequency of each number
        for (int num : nums) {
            frequency[num]++;
        }
        
        int result = 0;
        // XOR the numbers that appear exactly twice
        for (auto& entry : frequency) {
            if (entry.second == 2) {
                result ^= entry.first;
            }
        }
        
        return result;
    }
};