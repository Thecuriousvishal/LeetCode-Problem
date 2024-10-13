class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;
        int maxLength = 0;
        int i = 0;  // Left pointer of the window

        for (int j = 0; j < s.length(); j++){
            char currentChar = s[j];
            if (lastSeen.find(currentChar) != lastSeen.end() && lastSeen[currentChar] >= i){
                i = lastSeen[currentChar] + 1;
            }
            lastSeen[currentChar] = j;

            maxLength = max(maxLength, j - i + 1);
        }
        return maxLength;
    }
};