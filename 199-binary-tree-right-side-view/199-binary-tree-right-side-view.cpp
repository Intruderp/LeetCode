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
    vector<int> res;
    void dfs(TreeNode* root,int x)
    {
        if(root==NULL)
            return ;
        if(x>=res.size())
            res.push_back(root->val);
        dfs(root->right,x+1);
        dfs(root->left,x+1);
    }
    vector<int> rightSideView(TreeNode* root) 
    {
        dfs(root,0);
        return res;
    }
};