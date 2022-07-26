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
    int dfs(TreeNode* root,TreeNode* par,TreeNode* grandPar)
    {
        if(root==NULL)
            return 0;
        int cur=0;
        if(grandPar!=NULL and grandPar->val%2==0)
            cur=root->val;
        return cur+dfs(root->left,root,par)+dfs(root->right,root,par);
    }
    int sumEvenGrandparent(TreeNode* root) {
        return dfs(root,NULL,NULL);
    }
};