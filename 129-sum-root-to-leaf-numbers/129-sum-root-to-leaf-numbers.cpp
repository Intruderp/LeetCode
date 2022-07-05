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
    int dfs(TreeNode* root,string num)
    {
        if(root==NULL)
            return 0;
        if(root->left==NULL and root->right==NULL)
        {
            num.push_back('0'+root->val);
            int x=0,mul=1;
            for(int i=num.length()-1;i>=0;i--)
            {
                x+=(num[i]-'0')*mul;
                if(i>0)
                mul*=10;
            }
            return x;
        }
        return dfs(root->left,num+to_string(root->val))+dfs(root->right,num+to_string(root->val));
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root,"");
    }
};