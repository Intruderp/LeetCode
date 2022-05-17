/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* dfs(TreeNode* original,TreeNode* cloned,TreeNode* target)
    {
        if(original==NULL)
            return NULL;
        if(original->val==target->val)
            return cloned;
        if(dfs(original->left,cloned->left,target))
            return dfs(original->left,cloned->left,target);
        else if(dfs(original->right,cloned->right,target))
            return dfs(original->right,cloned->right,target);
        else
            return NULL;
            
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target)
    {
        return dfs(original,cloned,target);
    }
};