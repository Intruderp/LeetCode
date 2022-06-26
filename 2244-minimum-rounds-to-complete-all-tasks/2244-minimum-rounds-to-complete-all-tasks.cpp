class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> m;
        for(auto &task:tasks)
            m[task]++;
        int res=0;
        for(auto &it:m)
        {
            if(it.second==1)
                return -1;
            if(it.second%3==0)
                res+=it.second/3;
            else if(it.second==1)
                res+=2+(it.second-4)/3;
            else
                res+=it.second/3+1;
        }
        return res;
    }
};