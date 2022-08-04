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
    void dfs(TreeNode* root,bool &found,bool &res,int level)
    {
        if(level==0)
        {
            if(found and root==NULL)
                res=false;
            if(root)
                found=true;
            return ;
        }
        if(root==NULL)
        {
            res=false;
            return ;
        }
        dfs(root->right,found,res,level-1);
        dfs(root->left,found,res,level-1);
    }
    int height(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return max(height(root->left),height(root->right))+1;
    }
    bool isCompleteTree(TreeNode* root) {
        int level=height(root)-1;
        bool found=false,res=true;
        dfs(root,found,res,level);
        return res;
        
    }
};