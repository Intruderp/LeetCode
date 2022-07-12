class RandomizedCollection {
public:
    vector<int> nums;
    unordered_map<int,unordered_set<int>> m;
    int x,ind,ind2;
    RandomizedCollection() 
    {
        
    }
    bool insert(int val) 
    {
        bool ans=m.count(val);
        m[val].insert(nums.size());
        nums.push_back(val);
        return !ans;
    }
    
    bool remove(int val) 
    {
        bool ans=m.count(val);
        if(ans)
        {
            x=nums.back(),ind=nums.size()-1,ind2=*m[val].begin();
            nums[ind2]=x;
            nums.pop_back();
            m[val].erase(ind2);
            if(m[val].size()==0)
                m.erase(val);
            if(ind!=ind2)
            {
                m[x].erase(ind);
                m[x].insert(ind2);
            }
        }
        return ans;
    }
    
    int getRandom() 
    {
        return nums[random()%(nums.size())];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */