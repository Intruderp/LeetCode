class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long sum=0,s;
        priority_queue<int> q;
        for(int &num:target)
        {
            q.push(num);
            sum+=num;
        }
        while(q.top()>1)
        {
            int t=q.top();
            s=sum-t;
            q.pop();
            if(t<=s)
                return false;
            if(s==1)
                return true;
            if(s==0)
                return false;
            q.push(t%s);
            sum=s+t%s;
        }
        return sum==target.size();
    }
};