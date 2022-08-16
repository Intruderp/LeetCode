struct Node{
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
        Node* node=root;
        int bit;
        for(int b=31;b>=0;b--)
        {
            bit=(1<<b)&x ?1:0;
            if(!node->containsKey(bit))
                node->put(bit,new Node());
            node=node->get(bit);
        }
    }
    int maxXor(int &x)
    {
        int res=0,bit;
        Node* node=root;
        for(int b=31;b>=0;b--)
        {
            bit=(1<<b)&x ?1:0;
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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int n=queries.size(),m=nums.size(),i=0;
        vector<int> res(n,-1);
        for(int i=0;i<n;i++)
        {
            swap(queries[i][0],queries[i][1]);
            queries[i].push_back(i);
        }
        sort(nums.begin(),nums.end());
        sort(queries.begin(),queries.end());
        Trie trie;
        for(auto &query:queries)
        {
            while(i<m and query[0]>=nums[i])
            {
                trie.insert(nums[i]);
                i++;
            }
            if(i)
                res[query[2]]=trie.maxXor(query[1]);
        }
        return res;
    }
};