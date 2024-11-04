class Solution {
public:
    string compressedString(string word) {
        string comp;
        int n = word.length();

        // Start iterating through the string
        for (int i = 0; i < n; ) 
        {
            char currentChar = word[i];
            int count = 0; 

            // Count the number of times the current character repeats
            while (i < n && word[i] == currentChar && count < 9) 
            {
                count++;
                i++;
            }

            // Append count and character to the result
            comp += std::to_string(count) + currentChar;
        }

        return comp; 
    }
};