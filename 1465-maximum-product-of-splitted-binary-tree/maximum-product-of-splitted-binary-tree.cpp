class Solution {
public:
    long long totalSum = 0;
    long long maxProductSum = 0;
    const int MOD = 1e9 + 7;

    long long computeTotalSum(TreeNode* root) {
        if (!root) return 0;
        return root->val 
             + computeTotalSum(root->left) 
             + computeTotalSum(root->right);
    }

    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long leftSum = dfs(root->left);
        long long rightSum = dfs(root->right);

        long long subTreeSum = root->val + leftSum + rightSum;

        // product after cutting edge above this subtree
        long long product = subTreeSum * (totalSum - subTreeSum);
        maxProductSum = max(maxProductSum, product);

        return subTreeSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = computeTotalSum(root);
        dfs(root);
        return maxProductSum % MOD;
    }
};
