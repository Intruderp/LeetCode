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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) 
    {
        if(depth==1)
        {
            TreeNode *newRoot=new TreeNode(val);
            newRoot->left=root;
            return newRoot;
        }
        queue<TreeNode*> q;
        q.push(root);
        depth--;
        while(!q.empty() and depth>1)
        {
            int sz=q.size();
            while(sz--)
            {
                auto node=q.front();
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            depth--;
        }
        while(!q.empty())
        {
            auto node=q.front();
            TreeNode* leftNode=new TreeNode(val,node->left,NULL);
            TreeNode* rightNode=new TreeNode(val,NULL,node->right);
            node->left=leftNode;
            node->right=rightNode;
            q.pop();
        }
        return root;
    }
};