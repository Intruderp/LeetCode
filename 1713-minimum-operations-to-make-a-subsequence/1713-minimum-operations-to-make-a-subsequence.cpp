class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int n=arr.size(),m=target.size();
        unordered_map<int,int> ind;
        for(int i=0;i<m;i++)
        {
            ind[target[i]]=i;
        }
        vector<int> lis;
        for(auto &num:arr)
        {
            if(ind.count(num)==0)
                continue;
            num=ind[num];
            if(lis.size()==0)
                lis.push_back(num);
            else if(num>lis.back())
                lis.push_back(num);
            else
            {
                auto it=lower_bound(lis.begin(),lis.end(),num);
                *it=num;
            }
        }
        return m-lis.size();
    }
};