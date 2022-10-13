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
    int kthSmallest(TreeNode* root, int k)
    {
        TreeNode* res=new TreeNode(-1);
        find(root,res,k);
        return res->val;
    }
void find(TreeNode* root, TreeNode* &res,int& k) 
{
    if(root==NULL)
        return ;
    find(root->left,res,k);
    k--;
    if(k==0)
        res=root;
    find(root->right,res,k);
}
};