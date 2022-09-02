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
    void dfs(TreeNode* root,vector<int> &val)
    {
        if(root==NULL)
            return ;
        dfs(root->left,val);
        val.push_back(root->val);
        dfs(root->right,val);
    }
    TreeNode* buildTree(int start,int end,vector<int> &val)
    {
        if(start>end)
            return NULL;
        int mid=(start+end)/2;
        TreeNode *root=new TreeNode(val[mid]);
        root->left=buildTree(start,mid-1,val);
        root->right=buildTree(mid+1,end,val);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root)
    {
        vector<int> val;
        dfs(root,val);
        return buildTree(0,val.size()-1,val);
    }
};