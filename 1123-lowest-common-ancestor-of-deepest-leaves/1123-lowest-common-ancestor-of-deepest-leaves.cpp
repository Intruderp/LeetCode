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
    int help(TreeNode* node,int depth,int &maxDepth,TreeNode* &lca)
    {
        maxDepth=max(maxDepth,depth);
        if(node==NULL)
            return depth;
        int left=help(node->left,depth+1,maxDepth,lca);
        int right=help(node->right,depth+1,maxDepth,lca);
        if(right==left and right==maxDepth)       // this is a potential answer as it contain deepest node on both sides 
        {
            lca=node;               // this will be updated only if any node above this node also satisfy the condition
        }
        return max(left,right);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        TreeNode* lca=NULL;
        int maxDepth=0;
        help(root,0,maxDepth,lca);
        return lca;
    }
};