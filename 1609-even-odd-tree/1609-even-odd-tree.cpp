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
    bool isEvenOddTree(TreeNode* root) 
    {
        queue<TreeNode*> q;
        q.push(root);
        int level=0,sz,mini,maxi;
        while(!q.empty())
        {
            sz=q.size(),mini=INT_MAX,maxi=0;
            while(sz--)
            {
                auto f=q.front();
                q.pop();
                if(level%2)
                {
                    if(f->val%2 or f->val>=mini)
                        return false;
                    mini=f->val;
                }
                else
                {
                    if(f->val%2==0 or f->val<=maxi)
                        return false;
                    maxi=f->val;
                }
                if(f->left!=NULL)
                    q.push(f->left);
                if(f->right!=NULL)
                    q.push(f->right);
            }
            level++;
        }
        return true;
    }
};