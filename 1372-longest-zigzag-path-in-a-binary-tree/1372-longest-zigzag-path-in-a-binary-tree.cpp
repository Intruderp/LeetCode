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
    map<pair<TreeNode*,int>,int> dp;
    int help(TreeNode* root,int p)
    {
        if(dp.count({root,p}))
            return dp[{root,p}];
        int ans=0;
        if(root->left!=NULL and p==0)
            ans=max(help(root->left,1)+1,help(root->left,0));
        if(root->right!=NULL and p==0)
            ans=max(ans,max(help(root->right,2)+1,help(root->right,0)));
        if(p==1 and root->right!=NULL)
            ans=help(root->right,2)+1;
        if(p==2 and root->left!=NULL)
            ans=help(root->left,1)+1;
        return dp[{root,p}]=ans;
    }
    int longestZigZag(TreeNode* root) {
        return help(root,0);
    }
};