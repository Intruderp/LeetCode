class CountIntervals {
public:
    int res=0;
    set<pair<int,int>> s;
    CountIntervals()
    {
        
    }
    
    void add(int left, int right) 
    {
        int L=left;
        pair<int,int> p={left,0};
        auto it=s.lower_bound(p);
        set<pair<int,int>> temp;
        while(it!=s.end() and it->second<=right)
        {
            right=max(right,it->first);
            L=min(L,it->second);
            res-=it->first-it->second+1;
            s.erase(it++);
        }
        res+=right-L+1;
        s.insert({right,L});
    }
    
    int count() {
        return res;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */