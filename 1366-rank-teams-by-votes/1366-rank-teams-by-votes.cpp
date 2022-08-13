int cnt[26][26];
bool comp(char &a,char &b)
{
    for(int rank=0;rank<26;rank++)
    {
        if(cnt[a-'A'][rank]!=cnt[b-'A'][rank])
            return cnt[a-'A'][rank]>cnt[b-'A'][rank];
    }
    return a<b;
}
class Solution {
public:
    string rankTeams(vector<string>& votes) 
    {
        string res=votes[0];
        int n=res.length();
        memset(cnt,0,sizeof(cnt));
        for(string &vote:votes)
        {
            for(int i=0;i<n;i++)
            {
                cnt[vote[i]-'A'][i]++;
            }
        }
        sort(res.begin(),res.end(),comp);
        return res;
    }
};