/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root==p or root==q)
            return root;
        int mini=min(p->val,q->val),maxi=max(p->val,q->val);
        if(root->val>mini and root->val<maxi)
            return root;
        if(root->val<mini)
            return lowestCommonAncestor(root->right,p,q);
        else
            return lowestCommonAncestor(root->left,p,q);
        
    }
};