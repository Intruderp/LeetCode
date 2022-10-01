struct Node{
    Node* links[26];
    int cnt=0;
    void put(Node* node,char &c)
    {
        links[c-'a']=node;
    }
};
class Trie{
    Node* root;
public:
    Trie()
    {
        root=new Node();
    }
    void insert(string &s)
    {
        Node* node=root;
        for(char &c:s)
        {
            if(node->links[c-'a']==NULL)
                node->put(new Node(),c);
            node=node->links[c-'a'];
            node->cnt++;
        }
    }
    int count(string &s)
    {
        int res=0;
        Node* node=root;
        for(char &c:s)
        {
            node=node->links[c-'a'];
            res+=node->cnt;
        }
        return res;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) 
    {
        Trie trie;
        for(auto &word:words)
            trie.insert(word);
        vector<int> res;
        for(auto &word:words)
            res.push_back(trie.count(word));
        return res;
    }
};