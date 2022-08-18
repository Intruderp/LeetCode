class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int n=arr.size(),m=target.size();
        unordered_map<int,vector<int>> ind;
        for(int i=0;i<n;i++)
            ind[arr[i]].push_back(i);
        for(int i=0;i<m;i++)
        {
            if(ind.count(target[i]))
            {
                for(auto &index:ind[target[i]])
                    arr[index]=-i;
            }
        }
        vector<int> lis;
        for(auto &num:arr)
        {
            if(num>0)
                continue;
            num*=-1;
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