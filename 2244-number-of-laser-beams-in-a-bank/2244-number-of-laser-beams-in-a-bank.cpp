class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, result = 0;

        for (string &row : bank) {
            int count = count_if(row.begin(), row.end(), [](char c) { return c == '1'; });

            if (count > 0) {
                result += prev * count;
                prev = count; // Update previous row’s device count
            }
        }

        return result;
    }
};