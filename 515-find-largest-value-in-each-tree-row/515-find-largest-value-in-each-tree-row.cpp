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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(root==NULL)
            return res;
        int mx,sz;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size())
        {
            sz=q.size();
            mx=INT_MIN;
            while(sz--)
            {
                mx=max(mx,q.front()->val);
                if(q.front()->left!=NULL)
                    q.push(q.front()->left);
                if(q.front()->right!=NULL)
                    q.push(q.front()->right);
                q.pop();
                
            }
            res.push_back(mx);
        }
        return res;
    }
};