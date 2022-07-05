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
    string res="",path;
    void dfs(TreeNode* root)
    {
        if(root==NULL)
            return ;
        if(root->left==NULL and root->right==NULL)
        {
            string temp=path;
            reverse(temp.begin(),temp.end());
            if(res.size()==0 or temp<res)
                res=temp;
            return ;
        }
        if(root->left!=NULL)
        {
            path.push_back(root->left->val+'a');
            dfs(root->left);
            path.pop_back();
        }
        if(root->right!=NULL)
        {
            path.push_back(root->right->val+'a');
            dfs(root->right);
            path.pop_back();
        }
    }
    string smallestFromLeaf(TreeNode* root) {
        path.push_back(root->val+'a');
        dfs(root);
        return res;
    }
};