class Solution {
public:

    bool isBalanced(int x) {
        string s = to_string(x);
        vector<int> freq(10, 0);

        // Count occurrences of each digit
        for (char c : s) {
            freq[c - '0']++;
        }

        // Check the balanced condition
        for (char c : s) {
            int d = c - '0';
            if (freq[d] != d) return false;
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        int x = n + 1;
        while (true) {
            if (isBalanced(x)) return x;
            x++;
        }
    }
};