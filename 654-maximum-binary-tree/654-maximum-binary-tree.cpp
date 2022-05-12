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
    TreeNode* dfs(vector<int> &nums)
    {
        if(nums.size()==0)
            return NULL;
        int i=0;
        for(int j=0;j<nums.size();j++)
        {
            if(nums[j]>nums[i])
                i=j;
        }
        TreeNode *root=new TreeNode();
        root->val=nums[i];
        vector<int> left,right;
        for(int j=0;j<i;j++)
            left.push_back(nums[j]);
        for(int j=i+1;j<nums.size();j++)
            right.push_back(nums[j]);
        root->left=dfs(left);
        root->right=dfs(right);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        return dfs(nums);
    }
};