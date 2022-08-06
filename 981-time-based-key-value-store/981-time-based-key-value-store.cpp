class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> map;
    TimeMap() {
        
    }
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        string res="";
        if(map.count(key))
        {
            pair<int,string> p={timestamp+1,""};
            auto it=lower_bound(map[key].begin(),map[key].end(),p);
            if(it!=map[key].begin())
            {
                it--;
                res=it->second;
            }
        }
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */