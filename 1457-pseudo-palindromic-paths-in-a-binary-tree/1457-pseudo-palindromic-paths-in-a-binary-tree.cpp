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
    int dfs(TreeNode* root,vector<int> &cnt)
    {
        if(root==NULL)
            return 0;
        int poss=0;
        cnt[root->val]++;
        if(root->left==NULL and root->right==NULL)
        {
            int odd=0;
            for(int i=0;i<=9;i++)
            {
                odd+=cnt[i]%2;
            }
            if(odd<=1)
                poss=1;
        }
        int ans=poss+dfs(root->left,cnt)+dfs(root->right,cnt);
        cnt[root->val]--;
        return ans;
    }
    int pseudoPalindromicPaths (TreeNode* root) 
    {
        vector<int> cnt(10,0);
        return dfs(root,cnt);
    }
};