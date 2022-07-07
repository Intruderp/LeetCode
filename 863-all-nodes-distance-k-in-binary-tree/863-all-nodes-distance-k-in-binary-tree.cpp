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
    vector<int> adj[501];
    void dfs(TreeNode* root)
    {
        if(root->left)
        {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            dfs(root->left);
        }
        if(root->right)
        {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            dfs(root->right);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        dfs(root);
        queue<int> q;
        int level=0;
        vector<int> res,vis(501,0);
        vis[target->val]=1;
        q.push(target->val);
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                auto f=q.front();
                q.pop();
                if(level==k)
                    res.push_back(f);
                else if(level>k)
                    return res;
                for(auto &child:adj[f])
                {
                    if(vis[child]==0)
                    {
                        vis[child]=1;
                        q.push(child);
                    }
                }
            }
            level++;
        }
        return res;
    }
};