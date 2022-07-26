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
    vector<int> sum(TreeNode* root,int &res)
    {
        vector<int> v(2,0);
        if(root==NULL)
            return v;
        vector<int> left=sum(root->left,res);
        vector<int> right=sum(root->right,res);
        v[0]=left[0]+right[0]+root->val;
        v[1]=1+left[1]+right[1];
        res+=v[0]/v[1]==root->val;
        return v;
    }
    int averageOfSubtree(TreeNode* root) {
        int res=0;
        sum(root,res);
        return res;
    }
};