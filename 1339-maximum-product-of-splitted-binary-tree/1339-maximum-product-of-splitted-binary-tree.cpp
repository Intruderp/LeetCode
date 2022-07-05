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
    unordered_map<TreeNode*,int> m;
    long long totalSum,res=0,sum;
    int dfs(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int curSum=root->val;
        curSum+=dfs(root->left)+dfs(root->right);
        return m[root]=curSum;
    }
    void help(TreeNode* root)
    {
        if(root==NULL)
            return ;
        if(root->left!=NULL)
        {
            sum=m[root->left];
            res=max(res,sum*(totalSum-sum));
        }
        if(root->right!=NULL)
        {
            sum=m[root->right];
            res=max(res,sum*(totalSum-sum));
        }
        help(root->left);
        help(root->right);
    }
    int maxProduct(TreeNode* root) {
        dfs(root);
        totalSum=m[root];
        help(root);
        return res%1000000007;
    }
};