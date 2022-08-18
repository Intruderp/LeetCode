struct Node{
    Node* links[26];
    bool flag=false;
    bool containsKey(char &c)
    {
        return links[c-'a']!=NULL;
    }
    void put(char &c,Node* node)
    {
        links[c-'a']=node;
    }
    Node* get(char &c)
    {
        return links[c-'a'];
    }
};
class Trie{
private:
    Node* root;
public:
    Trie()
    {
        root=new Node();
    }
    void insert(string &word)
    {
        Node* node=root;
        for(char &c:word)
        {
            if(!node->containsKey(c))
                node->put(c,new Node());
            node=node->get(c);
        }
        node->flag=true;
    }
    Node* getRoot()
    {
        return root;
    }
};
class Solution {
private:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
public:
    void dfs(int i,int j,int &n,int &m,string &s,Node* root,vector<vector<char>>& board,vector<vector<int>> &vis,unordered_set<string> &x)
    {
        if(i<0 or j<0 or i>=n or j>=m or vis[i][j])
            return ;
        if(root->links[board[i][j]-'a']!=NULL)
        {
            root=root->get(board[i][j]);
            s.push_back(board[i][j]);
            if(root->flag)
                x.insert(s);
            vis[i][j]=1;
            for(int d=0;d<4;d++)
                dfs(i+dx[d],j+dy[d],n,m,s,root,board,vis,x);
            s.pop_back();
            vis[i][j]=0;
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        int n=board.size(),m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        Trie trie;
        Node* root=trie.getRoot();
        for(auto &word:words)
            trie.insert(word);
        unordered_set<string> x;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                string s;
                dfs(i,j,n,m,s,root,board,vis,x);
            }
        }
        vector<string> res{x.begin(),x.end()};
        return res;
        
    }
};