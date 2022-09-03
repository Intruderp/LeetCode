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
    bool check(TreeNode* node)
    {
        if(node==NULL)
            return false;
        if(node->val==1)
            return true;
        return check(node->left) or check(node->right);
    }
    void dfs(TreeNode* root)
    {
        if(root==NULL)
            return ;
        if(!check(root->left))
            root->left=NULL;
        else
            dfs(root->left);
        if(!check(root->right))
            root->right=NULL;
        else
            dfs(root->right);
    }
    TreeNode* pruneTree(TreeNode* root) {
        dfs(root);
        if(root->left==NULL and root->right==NULL and root->val==0)
            return NULL;
        return root;
    }
};