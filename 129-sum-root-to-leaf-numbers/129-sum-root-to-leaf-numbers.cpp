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
    string num;
    int dfs(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        if(root->left==NULL and root->right==NULL)
        {
            int x=root->val,mul=10,n=num.length();
            for(int i=n-1;i>=0;i--)
            {
                x+=(num[i]-'0')*mul;
                if(i>0)
                mul*=10;
            }
            return x;
        }
        num.push_back('0'+root->val);
        int sum=dfs(root->left)+dfs(root->right);
        num.pop_back();
        return sum;
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root);
    }
};