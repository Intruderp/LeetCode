/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,vector<TreeNode*>> adj;
    void dfs(TreeNode* root)
    {
        if(root->left)
        {
            adj[root].push_back(root->left);
            adj[root->left].push_back(root);
            dfs(root->left);
        }
        if(root->right)
        {
            adj[root].push_back(root->right);
            adj[root->right].push_back(root);
            dfs(root->right);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        dfs(root);
        queue<TreeNode*> q;
        int level=0;
        vector<int> res,vis(501,0);
        vis[target->val]=1;
        q.push(target);
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                auto f=q.front();
                q.pop();
                if(level==k)
                    res.push_back(f->val);
                else if(level>k)
                    return res;
                for(auto &child:adj[f])
                {
                    if(vis[child->val]==0)
                    {
                        vis[child->val]=1;
                        q.push(child);
                    }
                }
            }
            level++;
        }
        return res;
    }
};