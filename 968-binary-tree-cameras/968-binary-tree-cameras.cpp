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
    map<pair<TreeNode*,pair<int,int>>,int> dp;
    int help(TreeNode *root,int self,int par)
    {
        if(root==NULL)
            return 0;
        if(dp.count({root,{self,par}}))
            return dp[{root,{self,par}}];
        if(self==0 and par==0)
            return dp[{root,{self,par}}]=min({help(root->left,0,1)+help(root->right,0,1),help(root->right,1,0)+help(root->left,0,0),help(root->left,1,0)+help(root->right,0,0)})+1;
        else if(self==0)
            return dp[{root,{self,par}}]=min(help(root->left,0,0)+help(root->right,0,0),help(root->left,0,1)+help(root->right,0,1)+1);
        else
            return dp[{root,{self,par}}]=help(root->left,0,1)+help(root->right,0,1);
    }
    int minCameraCover(TreeNode* root) {
        return help(root,0,0);
    }
};