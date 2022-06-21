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
    int res=0;
    void dfs(TreeNode* root,int mx,int mn)
    {
        if(root==NULL)
            return ;
        res=max({res,abs(root->val-mx),abs(root->val-mn)});
        dfs(root->left,max(mx,root->val),min(mn,root->val));
        dfs(root->right,max(mx,root->val),min(mn,root->val));
    }
    int maxAncestorDiff(TreeNode* root) {
        dfs(root,root->val,root->val);
        return res;
    }
};