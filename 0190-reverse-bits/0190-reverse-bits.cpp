class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; ++i) {
            result <<= 1;           // Shift result left by 1 to make space for the next bit
            result |= (n & 1);      // Set the last bit of result to the last bit of n
            n >>= 1;                // Shift n right by 1 to process the next bit
        }
        return result;
    }
};