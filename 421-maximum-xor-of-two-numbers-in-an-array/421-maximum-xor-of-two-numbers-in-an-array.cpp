struct Node
{
    Node* links[2];
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
        int bit;
        Node* node=root;
        for(int b=31;b>=0;b--)
        {
            bit=0;
            if((1<<b)&x)
                bit=1;
            if(!node->containsKey(bit))
                node->put(bit,new Node());
            node=node->get(bit);
        }
    }
    int getMax(int &x)
    {
        int res=0,bit;
        Node* node=root;
        for(int b=31;b>=0;b--)
        {
            bit=(1<<b)&x ? 1:0;
            if(node->containsKey(1-bit))
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
    int findMaximumXOR(vector<int>& nums) {
        int res=0;
        Trie trie;
        for(auto &num:nums)
        {
            trie.insert(num);
        }
        for(auto &num:nums)
        {
            res=max(res,trie.getMax(num));
        }
        return res;
    }
};