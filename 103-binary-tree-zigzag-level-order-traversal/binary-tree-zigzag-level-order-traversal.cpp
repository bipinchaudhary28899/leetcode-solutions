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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        bool leftToRight=true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int levelLen=q.size();
            vector<int> levelElements(levelLen);
            
            for(int i=0;i<levelLen;i++){
                TreeNode* node = q.front();q.pop();
                int index = leftToRight? i: levelLen-i-1;
                levelElements[index]=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            result.push_back(levelElements);
            leftToRight=!leftToRight;
            
        }
        
        return result;
    }
};