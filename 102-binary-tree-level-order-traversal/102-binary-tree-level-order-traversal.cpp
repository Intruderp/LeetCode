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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        q.push(root);
        int sz;
        TreeNode* f;
        while(!q.empty())
        {
            sz=q.size();
            vector<int> v;
            while(sz--)
            {
                f=q.front();
                q.pop();
                v.push_back(f->val);
                if(f->left!=NULL)
                    q.push(f->left);
                if(f->right!=NULL)
                    q.push(f->right);
            }
            ans.push_back(v);
        }
        return ans;
    }
};