class Solution {
public:
   string multiply(string num1, string num2) {
    int n1 = num1.size();
    int n2 = num2.size();
    
    // Result can have at most n1 + n2 digits
    vector<int> result(n1 + n2, 0);
    
    // Multiply each digit of num2 with each digit of num1
    for (int i = n2 - 1; i >= 0; --i) {
        for (int j = n1 - 1; j >= 0; --j) {
            int mul = (num2[i] - '0') * (num1[j] - '0');
            int sum = mul + result[i + j + 1];
            result[i + j + 1] = sum % 10; // current position
            result[i + j] += sum / 10;   // carry
        }
    }
    
    // Skip leading zeros in the result
    int start = 0;
    while (start < result.size() && result[start] == 0) {
        start++;
    }
    
    // If all are zeros
    if (start == result.size()) {
        return "0";
    }
    
    // Convert the vector<int> to string
    string res = "";
    for (int i = start; i < result.size(); ++i) {
        res += to_string(result[i]);
    }
    
    return res;
}

};