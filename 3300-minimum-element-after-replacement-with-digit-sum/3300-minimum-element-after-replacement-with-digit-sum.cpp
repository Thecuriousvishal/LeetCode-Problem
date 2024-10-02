class Solution {
public:
        int sumOfDigits(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minElement(vector<int>& nums) {
        for (int& num : nums) {
            num = sumOfDigits(num);
        }
        return *min_element(nums.begin(), nums.end());
    }
};