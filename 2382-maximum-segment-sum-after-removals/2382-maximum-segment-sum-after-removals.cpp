class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) 
    {
        int n=nums.size(),l,r,mid;
        vector<long long> res,pre(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            pre[i]+=pre[i-1]+nums[i];
        }
        map<long long,int> cnt;
        cnt[pre[n-1]]=1;
        set<pair<int,int>> intervals;
        long long sum;
        removeQueries.pop_back();
        intervals.insert({n-1,0});
        for(auto &query:removeQueries)
        {
            pair<int,int> p={query,0};
            auto it=intervals.lower_bound(p);
            l=it->second,r=it->first;
            sum=pre[r]- (l ? pre[l-1]:0);
            cnt[sum]--;
            if(cnt[sum]==0)
                cnt.erase(sum);
            intervals.erase(it);
            if(query-1>=l)
            {
                intervals.insert({query-1,l});
                sum=pre[query-1]-(l?pre[l-1]:0);
                cnt[sum]++;
            }
            if(r>=query+1)
            {
                intervals.insert({r,query+1});
                sum=pre[r]-pre[query];
                cnt[sum]++;
            }
            res.push_back(cnt.rbegin()->first);
        }
        res.push_back(0);
        return res;
    }
};