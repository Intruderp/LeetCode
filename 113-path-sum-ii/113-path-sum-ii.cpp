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
    vector<vector<int>> ans;
    void dfs(TreeNode* root,int sum,int target,vector<int> &v)
    {
        if(root==NULL)
            return ;
        if(root->left==NULL and root->right==NULL and (sum+root->val)==target)
        {
            v.push_back(root->val);
            ans.push_back(v);
            v.pop_back();
            return ;
        }
        v.push_back(root->val);
        dfs(root->left,sum+root->val,target,v);
        dfs(root->right,sum+root->val,target,v);
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) 
    {
        vector<int> v;
        dfs(root,0,target,v);
        return ans;
    }
};