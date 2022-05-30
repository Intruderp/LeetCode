#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int,string>, null_type, less<pair<int,string>>, rb_tree_tag, tree_order_statistics_node_update> pbds;
class SORTracker {
public:
    pbds s;
    int cnt=0;
    SORTracker() {
        
    }
    void add(string name, int score) {
        s.insert({-score,name});
    }
    
    string get() {
        auto res=s.find_by_order(cnt);
        cnt++;
        return res->second;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */