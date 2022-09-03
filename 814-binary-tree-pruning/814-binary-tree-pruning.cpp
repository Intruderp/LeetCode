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
    bool dfs(TreeNode* root,TreeNode* par,char dir)
    {
        if(root==NULL)
            return false;
        bool left=dfs(root->left,root,'L');
        bool right=dfs(root->right,root,'R');
        bool exist=left or right or root->val==1;
        if(!exist)
        {
            if(par!=NULL)
                dir=='L' ? par->left=NULL: par->right=NULL;
        }
        return exist;
    }
    TreeNode* pruneTree(TreeNode* root) {
        dfs(root,NULL,'X');
        if(root->left==NULL and root->right==NULL and root->val==0)
            return NULL;
        return root;
    }
};