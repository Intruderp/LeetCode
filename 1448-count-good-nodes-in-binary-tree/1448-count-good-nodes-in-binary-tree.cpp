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
    int dfs(TreeNode* root,int maxValue)
    {
        if(root==NULL)
            return 0;
        int isGood=1;
        if(root->val<maxValue)
            isGood=0;
        return isGood+dfs(root->left,max(maxValue,root->val))+dfs(root->right,max(maxValue,root->val));
    }
    int goodNodes(TreeNode* root) {
        return dfs(root,INT_MIN);
    }
};