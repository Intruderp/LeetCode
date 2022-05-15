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
    int maxDistance(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return max(maxDistance(root->left),maxDistance(root->right))+1;
    }
    int sum(TreeNode* root,int dist)
    {
        if(root==NULL)
            return 0;
        if(dist==1)
            return root->val;
        return sum(root->left,dist-1)+sum(root->right,dist-1);
    }
    int deepestLeavesSum(TreeNode* root) 
    {
        int dist=maxDistance(root);
        return sum(root,dist);
    }
};