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
    void dfs(TreeNode* root,TreeNode* par)
    {
        if(root==NULL)
            return ;
        dfs(root->left,root);
        dfs(root->right,root);
        if(root->val!=1)
        {
            int e=root->val-1;
            res+=abs(e);
            if(par!=NULL);
                par->val+=e;
        }
            
    }
    int distributeCoins(TreeNode* root) {
        dfs(root,NULL);
        return res;
    }
};