class Solution {
public:
    unordered_map<int,int> inMap;
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int left, int right) {
        if (left > right) return nullptr;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int mid = inMap[rootVal];

        root->left  = build(preorder, inorder, left, mid - 1);
        root->right = build(preorder, inorder, mid + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        return build(preorder, inorder, 0, inorder.size() - 1);
    }
};
