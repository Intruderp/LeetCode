/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
        if(end<start)
            return NULL;
        int mid=(start+end)/2;
        TreeNode *node=new TreeNode(nums[mid]);
        node->left=help(start,mid-1,nums);
        node->right=help(mid+1,end,nums);
        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)
            return NULL;
        vector<int> nums;
        while(head!=NULL)
        {
            nums.push_back(head->val);
            head=head->next;
        }
        return help(0,nums.size()-1,nums);
    }
};