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
    bool b;
    bool isLeaf(TreeNode* root)
    {
        if(root==NULL)
            return false;
        if(root->left==NULL and root->right==NULL)
            return true;
        return false;
    }
    void dfs(TreeNode *root,int target)
    {
        if(root==NULL)
            return ;
        if(isLeaf(root->left))
        {
            if(root->left->val==target)
            {
                b=true;
                root->left=NULL;
            }
        }
        else 
            dfs(root->left,target);
        if(isLeaf(root->right))
        {
            if(root->right->val==target)
            {
                b=true;
                root->right=NULL;
            }
        }
        else 
            dfs(root->right,target);
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        do{
            b=false;
            dfs(root,target);
        }while(b);
        if(isLeaf(root) and root->val==target)
            return NULL;
        return root;
    }
};