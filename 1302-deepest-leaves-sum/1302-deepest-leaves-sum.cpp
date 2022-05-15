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
    int deepestLeavesSum(TreeNode* root) 
    {
        int sum=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            sum=0;
            for(int i=q.size()-1;i>=0;i--)
            {
                TreeNode* f=q.front();
                q.pop();
                sum+=f->val;
                if(f->left)
                    q.push(f->left);
                if(f->right)
                    q.push(f->right);
            }
        }
        return sum;
    }
};