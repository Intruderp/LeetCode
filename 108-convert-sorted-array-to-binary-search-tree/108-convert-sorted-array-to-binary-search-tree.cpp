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
    TreeNode* help(int start,int end,vector<int> &nums)
    {
        if(start>end)
            return NULL;
        int mid=(start+end)/2;
        TreeNode* node=new TreeNode(nums[mid]);
        node->left=help(start,mid-1,nums);
        node->right=help(mid+1,end,nums);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return help(0,n-1,nums);
    }
};