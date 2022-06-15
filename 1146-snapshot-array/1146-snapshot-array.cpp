class SnapshotArray {
public:
    vector<pair<int,int>> v[50000];
    int s=0;
    SnapshotArray(int length) 
    {
        for(int i=0;i<length;i++)
            v[i].push_back({0,0});
    }
    
    void set(int index, int val) 
    {
        if(s==0)
            v[index][0]={0,val};
        else
            v[index].push_back({s,val});
    }
    
    int snap()
    {
        s++;
        return s-1;
    }
    
    int get(int index, int snap_id) 
    {
        pair<int,int> p={snap_id,INT_MAX};
        auto it=upper_bound(v[index].begin(),v[index].end(),p);
        it--;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */