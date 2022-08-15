struct Node
{
    Node* links[26];
    bool flag=false;
    bool containsKey(char &c)
    {
        return links[c-'a']!=NULL;
    }
    void setKey(char &c,Node *node)
    {
        links[c-'a']=node;
    }
    Node* getKey(char &c)
    {
        return links[c-'a'];
    }
};
class Trie {
private:
    Node *root;
public:
    Trie() 
    {
        root=new Node();
    }
    
    void insert(string word) 
    {
        Node* node=root;
        for(char &c:word)
        {
            if(!node->containsKey(c))
            {
                node->setKey(c,new Node());
            }
            node=node->getKey(c);
        }
        node->flag=true;
    }
    
    bool search(string word) 
    {
        Node* node=root;
        for(char &c:word)
        {
            if(!node->containsKey(c))
                return false;
            node=node->getKey(c);
        }
        return node->flag;
    }
    
    bool startsWith(string prefix) 
    {
        Node* node=root;
        for(char &c:prefix)
        {
            if(!node->containsKey(c))
                return false;
            node=node->getKey(c);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */