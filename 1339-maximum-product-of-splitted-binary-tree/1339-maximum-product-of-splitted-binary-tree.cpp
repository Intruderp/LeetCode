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
    long long totalSum,res=0;
    int dfs(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int curSum=root->val;
        curSum+=dfs(root->left)+dfs(root->right);
        res=max(res,curSum*(totalSum-curSum));
        return curSum;
    }
    int sum(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return root->val+sum(root->left)+sum(root->right);
    }
    int maxProduct(TreeNode* root) {
        totalSum=sum(root);
        dfs(root);
        return res%1000000007;
    }
};