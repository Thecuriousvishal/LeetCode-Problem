class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int XOR1 = 0, XOR2 = 0;

        // XOR all elements in arr1
        for (int num : arr1) {
            XOR1 ^= num;
        }

        // XOR all elements in arr2
        for (int num : arr2) {
            XOR2 ^= num;
        }

        // The result is XOR1 AND XOR2
        return XOR1 & XOR2;
    }
};