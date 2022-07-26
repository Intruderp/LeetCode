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
    unordered_map<TreeNode*,int> subTreeSize;
    int help(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int sz=1+help(root->left)+help(root->right);
        return subTreeSize[root]=sz;
    }
    int sum(TreeNode* root,int &res)
    {
        if(root==NULL)
            return 0;
        int s=root->val+sum(root->left,res)+sum(root->right,res);
        res+=s/subTreeSize[root]==root->val;
        return s;
    }
    int averageOfSubtree(TreeNode* root) {
        help(root);
        int res=0;
        sum(root,res);
        return res;
    }
};