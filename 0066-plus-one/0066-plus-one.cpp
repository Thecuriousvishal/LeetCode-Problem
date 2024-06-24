class Solution {
public:
     vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Start from the least significant digit
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                // No need for further increment, just increment and return
                digits[i]++;
                return digits;
            } else {
                // Overflow case, set this digit to 0
                digits[i] = 0;
            }
        }
        
        // If we are here, it means all digits were 9 (like 999...9)
        // So we need to add an extra 1 at the beginning
        digits.insert(digits.begin(), 1);
        
        return digits;
    }
};