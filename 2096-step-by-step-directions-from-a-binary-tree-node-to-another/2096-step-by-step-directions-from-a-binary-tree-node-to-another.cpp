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
    TreeNode* l;
    TreeNode* LCA(TreeNode* root,int node,int node2)
    {
        if(root==NULL or root->val==node or root->val==node2)
            return root;
        TreeNode* left=LCA(root->left,node,node2);
        TreeNode* right=LCA(root->right,node,node2);
        if(left==NULL)
            return right;
        else if(right==NULL)
            return left;
        return root;
    }
    string path;
    bool found=false;
    void dfs(TreeNode* root,int val)
    {
        if(root==NULL)
            return;
        if(root->val==val)
        {
            found=true;
            return ;
        }
        path.push_back('L');
        dfs(root->left,val);
        if(found)
            return ;
        path.back()='R';
        dfs(root->right,val);
        if(found)
            return ;
        path.pop_back();
    }
    int steps(TreeNode* root,int val)
    {
        if(root==NULL)
            return 100000;
        if(root->val==val)
            return 0;
        return min(steps(root->left,val),steps(root->right,val))+1;
    }
    string getDirections(TreeNode* root, int startVal, int destValue) {
        l=LCA(root,startVal,destValue);
        string res;
        dfs(l,destValue);
        int step=steps(l,startVal);
        while(step--)
            res.push_back('U');
        res+=path;
        return res;
    }
};