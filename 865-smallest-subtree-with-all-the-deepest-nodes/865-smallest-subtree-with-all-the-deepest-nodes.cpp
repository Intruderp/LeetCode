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
    int depthOfTree(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return max(depthOfTree(root->left),depthOfTree(root->right))+1;
    }
    int deepestNodes(TreeNode* root,int curDepth,int maxDepth)
    {
        if(root==NULL)
            return 0;
        if(curDepth==maxDepth)
            return 1;
        return deepestNodes(root->left,curDepth+1,maxDepth)+deepestNodes(root->right,curDepth+1,maxDepth);
    }
    int help(TreeNode* root,int &count,int curDepth,int &maxDepth,TreeNode* &res)
    {
        if(root==NULL)
            return 0;
        int x=0;
        if(curDepth==maxDepth)
            x=1;
        int deepestNodesCnt=help(root->left,count,curDepth+1,maxDepth,res)+help(root->right,count,curDepth+1,maxDepth,res)+x;
        if(deepestNodesCnt==count and res->val==-1)
        {
            res=root;
        }
        return deepestNodesCnt;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) 
    {
        int depth=depthOfTree(root);
        int count=deepestNodes(root,1,depth);
        TreeNode *res=new TreeNode(-1);
        help(root,count,1,depth,res);
        return res;
    }
};