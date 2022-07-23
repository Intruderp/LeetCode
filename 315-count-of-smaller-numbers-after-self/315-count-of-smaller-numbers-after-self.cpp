#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int,null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;
class Solution {
public:
    vector<int> countSmaller(vector<int>& a)
    {
        vector<int> ans;
        pbds s;
        int x;
        for(int &i:a)
            s.insert(i);
        for(auto &i:a)
        {
            auto it=s.upper_bound(i);
            s.erase(it);
            x=s.order_of_key(i);
            ans.push_back(x);
        }
        return ans;
    }
};