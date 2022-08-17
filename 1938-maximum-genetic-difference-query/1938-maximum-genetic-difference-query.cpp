struct Node{
    Node* links[2];
    int cnt=0;
    bool containsKey(int bit)
    {
        return links[bit]!=NULL;
    }
    void put(int bit,Node* node)
    {
        links[bit]=node;
    }
    Node* get(int bit)
    {
        return links[bit];
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
    void insert(int &x)
    {
        Node* node=root;
        int bit;
        for(int b=31;b>=0;b--)
        {
            bit=(1<<b)&x ?1:0;
            if(!node->containsKey(bit))
                node->put(bit,new Node());
            node=node->get(bit);
            node->cnt++;
        }
    }
    void remove(int &x)
    {
        Node* node=root;
        int bit;
        for(int b=31;b>=0;b--)
        {
            bit=(1<<b)&x ?1:0;
            if(!node->containsKey(bit))
                node->put(bit,new Node());
            node=node->get(bit);
            node->cnt--;
        }
    }
    int maxXor(int &x)
    {
        int res=0,bit;
        Node* node=root;
        for(int b=31;b>=0;b--)
        {
            bit=(1<<b)&x ?1:0;
            if(node->containsKey(1-bit) and node->get(1-bit)->cnt)
            {
                res|=(1<<b);
                node=node->get(1-bit);
            }
            else
                node=node->get(bit);
        }
        return res;
    }
};
class Solution {
public:
    void dfs(int src,int par,vector<int> adj[],unordered_map<int,vector<pair<int,int>>> &map,Trie &trie,vector<int> &res)
    {
        trie.insert(src);
        if(map.count(src))
        {
            for(auto &it:map[src])
            {
                  res[it.second]=trie.maxXor(it.first);
            }
        }
        for(auto &child:adj[src])
        {
            if(child!=par)
            {
                dfs(child,src,adj,map,trie,res);
            }
        }
        trie.remove(src);
    }
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        Trie trie;
        int n=parents.size(),m=queries.size(),root=-1;
        unordered_map<int,vector<pair<int,int>>> map;
        vector<int> res(m),adj[n];
        for(int i=0;i<n;i++)
        {
            if(parents[i]==-1)
                root=i;
            else
                adj[parents[i]].push_back(i);
        }
        for(int i=0;i<m;i++)
            map[queries[i][0]].push_back({queries[i][1],i});
        dfs(root,-1,adj,map,trie,res);
        return res;
    }
};