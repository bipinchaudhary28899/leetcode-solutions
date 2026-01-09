class Solution {
public:
    pair<int, TreeNode*> dfs(TreeNode* node) {
        if (!node) return {0, nullptr};

        auto left = dfs(node->left);
        auto right = dfs(node->right);

        if (left.first > right.first) {
            return {left.first + 1, left.second};
        }
        else if (right.first > left.first) {
            return {right.first + 1, right.second};
        }
        else {
            return {left.first + 1, node};
        }
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};
