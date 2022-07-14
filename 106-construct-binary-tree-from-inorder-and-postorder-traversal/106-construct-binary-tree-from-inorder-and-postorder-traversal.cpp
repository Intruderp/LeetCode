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
    unordered_map<int,int> posn;
    TreeNode* help(int postStart,int postEnd,vector<int> &postorder,int inStart,int inEnd,vector<int> &inorder)
    {
        if(postStart>postEnd or inStart>inEnd)
            return NULL;
        int p=posn[postorder[postEnd]],left=p-inStart;
        TreeNode* node=new TreeNode(postorder[postEnd]);
        node->left=help(postStart,postStart+left-1,postorder,inStart,p-1,inorder);
        node->right=help(postStart+left,postEnd-1,postorder,p+1,inEnd,inorder);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++)
            posn[inorder[i]]=i;
        return help(0,n-1,postorder,0,n-1,inorder);
    }
};