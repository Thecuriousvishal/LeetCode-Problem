/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long totalSum = 0;
    long long ans = 0;
    const int MOD = 1e9 + 7;

    long long dfsSum(TreeNode* root) {
        if (!root) return 0;
        long long left = dfsSum(root->left);
        long long right = dfsSum(root->right);

        return root->val + left + right;
    }

    long long dfs(TreeNode* root) {
        if (!root) return 0;
        long long left = dfs(root->left);
        long long right = dfs(root->right);
        long long currSum = root->val + left + right;
        ans = max(ans, currSum * (totalSum - currSum));

        return currSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = dfsSum(root);  
        dfs(root);                
        return ans % MOD;
    }
};