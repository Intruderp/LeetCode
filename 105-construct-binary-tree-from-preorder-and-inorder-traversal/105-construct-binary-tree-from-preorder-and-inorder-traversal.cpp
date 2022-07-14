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
    map<int,int> posn;
    TreeNode* help(int preStart,int preEnd,vector<int> &preorder,int inStart,int inEnd,vector<int> &inorder)
    {
        if(preStart>preEnd or inStart>inEnd)
            return NULL;
        int p=posn[preorder[preStart]];
        int left=p-inStart;
        TreeNode* node=new TreeNode(inorder[p]);
        node->left=help(preStart+1,preStart+left,preorder,inStart,p-1,inorder);
        node->right=help(preStart+left+1,preEnd,preorder,p+1,inEnd,inorder);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++)
            posn[inorder[i]]=i;
        return help(0,n-1,preorder,0,n-1,inorder);
    }
};