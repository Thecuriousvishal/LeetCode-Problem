class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;
    
        for (string s : strs) {
            // Sort the string to form the key
            string sortedStr = s;
            sort(sortedStr.begin(), sortedStr.end());

            // Group anagrams together by adding to the hash map
            anagramMap[sortedStr].push_back(s);
        }

        // Prepare the result by collecting all the grouped anagrams
        vector<vector<string>> result;
        for (auto& entry : anagramMap) {
            result.push_back(entry.second);
        }

        return result;
    }
};