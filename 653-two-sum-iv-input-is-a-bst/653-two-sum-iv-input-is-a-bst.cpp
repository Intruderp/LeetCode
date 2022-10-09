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
    bool check(TreeNode* root,int req,TreeNode* &node)
    {
        if(root==NULL)
            return false;
        if(root!= node and root->val==req)
            return true;
        return root->val>req ? check(root->left,req,node) : check(root->right,req,node);
    }
    TreeNode* node=new TreeNode(INT_MIN);
    bool findTarget(TreeNode* root, int &k) 
    {
        if(node->val==INT_MIN)
            node=root;
        if(root==NULL)
            return false;
        if(check(node,k-root->val,root))
            return true;
        return findTarget(root->left,k) or findTarget(root->right,k);
    }
};