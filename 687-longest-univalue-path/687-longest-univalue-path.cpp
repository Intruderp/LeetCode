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
    int dfs(TreeNode* root,int &res)
    {
        if(root==NULL)
            return 0;
        int l=dfs(root->left,res),r=dfs(root->right,res),x=0,y=0;
        if(root->left and root->left->val==root->val)
            x=l+1;
        if(root->right and root->right->val==root->val)
            y=r+1;
        res=max(res,x+y);
        return max(x,y);
    }
    int longestUnivaluePath(TreeNode* root) 
    {
        int res=0;
        dfs(root,res);
        return res;
    }
};