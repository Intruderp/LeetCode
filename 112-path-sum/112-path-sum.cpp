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
    bool ans;
    void dfs(TreeNode* root,int sum,int target)
    {
        if(root==NULL or ans)
            return ;
        if(root->left==NULL and root->right==NULL and (sum+root->val)==target)
        {
            ans=true;
            return ;
        }
        dfs(root->left,sum+root->val,target);
        dfs(root->right,sum+root->val,target);
    }
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        ans=false;
        dfs(root,0,targetSum);
        return ans;
    }
};