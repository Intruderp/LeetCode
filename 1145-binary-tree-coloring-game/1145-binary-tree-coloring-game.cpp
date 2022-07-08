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
    TreeNode* findNode(TreeNode* root,int val)
    {
        if(root==NULL)
            return NULL;
        if(root->val==val)
            return root;
        return max(findNode(root->left,val),findNode(root->right,val));
    }
    int subTreeSize(TreeNode* node)
    {
        if(node==NULL)
            return 0;
        return subTreeSize(node->left)+subTreeSize(node->right)+1;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode *node=findNode(root,x);
        vector<int> comp(3);
        comp[0]=subTreeSize(node->left),comp[1]=subTreeSize(node->right);
        comp[2]=n-(comp[0]+comp[1]+1);
        sort(comp.begin(),comp.end());
        return comp[2]>comp[0]+comp[1]+1;
    }
};