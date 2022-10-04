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
    bool dfs(TreeNode* root,int sum,int target)
    {
        if(root==NULL)
            return false;
        if(root->left==NULL and root->right==NULL and (sum+root->val)==target)
            return true;
        return dfs(root->left,sum+root->val,target) or dfs(root->right,sum+root->val,target);
    }
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        return dfs(root,0,targetSum);
    }
};