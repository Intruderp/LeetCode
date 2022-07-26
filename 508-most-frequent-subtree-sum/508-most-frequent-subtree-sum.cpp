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
    unordered_map<int,int> m;
    int mx=0;
    int sum(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int s=root->val+sum(root->left)+sum(root->right);
        m[s]++;
        mx=max(mx,m[s]);
        return s;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        sum(root);
        vector<int> res;
        for(auto &it:m)
        {
            if(it.second==mx)
                res.push_back(it.first);
        }
        return res;
    }
};