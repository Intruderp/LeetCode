class NumberContainers {
public:
    unordered_map<int,set<int>> m;
    unordered_map<int,int> ind;
    NumberContainers() 
    {
        
    }
    
    void change(int index, int number) 
    {
        if(ind.count(index))
        {
            m[ind[index]].erase(index);
        }
        ind[index]=number;
        m[number].insert(index);
    }
    
    int find(int number) 
    {
        if(m.count(number)==0 or m[number].size()==0)
            return -1;
        return *m[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */