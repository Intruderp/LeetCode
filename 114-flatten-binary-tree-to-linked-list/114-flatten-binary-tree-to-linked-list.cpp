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
    vector<int> nodes;
    void preorder(TreeNode* root)
    {
        if(root==NULL)
            return ;
        nodes.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    void flatten(TreeNode* root) 
    {
        preorder(root);
        int n=nodes.size();
        TreeNode* head=root;
        if(root==NULL)
            return ;
        head->left=NULL;
        head->right=NULL;
        head->val=nodes[0];
        for(int i=1;i<n;i++)
        {
            TreeNode* x=new TreeNode();
            x->left=NULL;
            x->right=NULL;
            x->val=nodes[i];
            head->right=x;
            head=x;
        }
    }
};