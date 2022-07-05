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
    int dfs(TreeNode* root,int num)
    {
        if(root==NULL)
            return 0;
        if(root->left==NULL and root->right==NULL)
           return num*10+root->val;
        return dfs(root->left,num*10+root->val)+dfs(root->right,num*10+root->val);
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
};