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
    int maxDepth(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
    void count(TreeNode* root,int level,int &depth,int &cnt)
    {
        if(root==NULL)
            return ;
        if(depth==level+1)
            cnt++;
        count(root->left,level+1,depth,cnt);
        count(root->right,level+1,depth,cnt);
    }
    int help(TreeNode* root,TreeNode* &res,int level,int &cnt,int &depth,int &maxi)
    {
        if(root==NULL)
            return 0;
        if(depth==level+1)
        {
            if(cnt==1)
            {
                maxi=level;
                res=root;
            }
            return 1;
        }
        int deepestLeavesCnt=help(root->left,res,level+1,cnt,depth,maxi)+help(root->right,res,level+1,cnt,depth,maxi);
        if(deepestLeavesCnt==cnt and level>maxi)
        {
            maxi=level;
            res=root;
        }
        return deepestLeavesCnt;
            
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) 
    {
        int depth=maxDepth(root),cnt=0,maxi=-1;
        count(root,0,depth,cnt);
        TreeNode* res=NULL;
        help(root,res,0,cnt,depth,maxi);
        return res;
    }
};