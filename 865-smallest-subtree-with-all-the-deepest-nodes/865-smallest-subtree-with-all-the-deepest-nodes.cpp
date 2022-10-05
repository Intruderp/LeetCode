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
    pair<int,TreeNode*> help(TreeNode* root)
    {
        if(root==NULL)
            return {0,NULL};
        auto left=help(root->left),right=help(root->right);
        int leftDepth=left.first;
        int rightDepth=right.first;
        if(leftDepth==rightDepth)
            return {leftDepth+1,root};
        else if(leftDepth>rightDepth)
            return {leftDepth+1,left.second};
        else
            return {rightDepth+1,right.second};
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) 
    {
        return help(root).second;
    }
};