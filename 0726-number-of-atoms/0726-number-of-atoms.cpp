class Solution {
public:
    string countOfAtoms(string formula) {
        stack<unordered_map<string, int>> stk; // Stack to handle parentheses
        unordered_map<string, int> currentMap;
        int i = 0, n = formula.size();
        
        while (i < n) {
            if (formula[i] == '(') {
                // Push the current map to the stack and start a new one
                stk.push(currentMap);
                currentMap.clear();
                i++;
            } else if (formula[i] == ')') {
                // We are closing a parenthesis, so we will multiply the elements inside
                i++;
                int num = 0;
                while (i < n && isdigit(formula[i])) {
                    num = num * 10 + (formula[i] - '0');
                    i++;
                }
                num = max(1, num);  // Default multiplier is 1 if no number follows

                // Pop the top map from the stack and add the counts to it
                unordered_map<string, int> temp = currentMap;
                currentMap = stk.top();
                stk.pop();
                
                // Multiply each element in temp by num and add to currentMap
                for (const auto& p : temp) {
                    currentMap[p.first] += p.second * num;
                }
            } else {
                // Parse an element name (starts with uppercase, may have lowercase letters)
                int start = i++;
                while (i < n && islower(formula[i])) i++;
                string element = formula.substr(start, i - start);

                // Parse the count (if any) after the element
                int num = 0;
                while (i < n && isdigit(formula[i])) {
                    num = num * 10 + (formula[i] - '0');
                    i++;
                }
                num = max(1, num);  // Default count is 1 if no number follows

                // Add the element to the current map
                currentMap[element] += num;
            }
        }

        // Sort the elements and construct the result string
        map<string, int> sortedMap(currentMap.begin(), currentMap.end());
        string result;
        for (const auto& p : sortedMap) {
            result += p.first;
            if (p.second > 1) result += to_string(p.second);
        }

        return result;
    }
};