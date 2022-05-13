/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) 
    {
        if(root==NULL)
            return NULL;
        Node* ans=root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                Node* f=q.front();
                q.pop();
                if(!q.empty() and f!=NULL and sz)
                  f->next=q.front();
                if(f->left!=NULL)
                    q.push(f->left);
                if(f->right!=NULL)
                    q.push(f->right);
                
            }
        }
        return ans;
    }
};