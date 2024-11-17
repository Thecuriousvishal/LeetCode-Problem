class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        int i = 0, n1 = word1.length(), n2 = word2.length();

        // Merge characters alternately
        while (i < n1 && i < n2) {
            result += word1[i];
            result += word2[i];
            i++;
        }

        // Append the remaining part of the longer string
        if (i < n1) {
            result += word1.substr(i);
        }
        if (i < n2) {
            result += word2.substr(i);
        }

        return result;
    }
};