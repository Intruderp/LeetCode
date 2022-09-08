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
    vector<int> inorderTraversal(TreeNode* root)
    {
        stack<TreeNode*> stack;
        vector<int> inorder;
        while(root!=NULL or !stack.empty())
        {
            if(root!=NULL)
            {
                stack.push(root);
                root=root->left;
            }
            else
            {
                inorder.push_back(stack.top()->val);
                root=stack.top()->right;
                stack.pop();
            }
        }
        return inorder;
    }
};