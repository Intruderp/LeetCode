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
    vector<int> sum;
    int dfs(TreeNode* root,int level)
    {
        if(root==NULL)
            return 0;
        sum[level]+=root->val;
        return max(dfs(root->left,level+1),dfs(root->right,level+1))+1;
    }
    int maxLevelSum(TreeNode* root) {
        int mx=INT_MIN,res=0;
        sum.resize(10001,0);
        int depth=dfs(root,1);
        for(int level=1;level<=depth;level++)
        {
            if(sum[level]>mx)
            {
                mx=sum[level];
                res=level;
            }
        }
        return res;
    }
};