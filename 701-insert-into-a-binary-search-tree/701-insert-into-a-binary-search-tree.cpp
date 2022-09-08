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
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        if(root==NULL)
            return new TreeNode(val);
        TreeNode *node=root,*prev=NULL;
        while(node)
        {
            prev=node;
            if(node->val<val)
                node=node->right;
            else
                node=node->left;
        }
        if(prev->val<val)
            prev->right=new TreeNode(val);
        else
            prev->left=new TreeNode(val);
        return root;
    }
};