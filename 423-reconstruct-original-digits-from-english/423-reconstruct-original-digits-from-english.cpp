class Solution {
public:
    string originalDigits(string s) {
        vector<int> cnt(26,0),ans(10,0);
        for(char &c:s)
            cnt[c-'a']++;
        ans[0]=cnt['z'-'a'];
        ans[2]=cnt['w'-'a'];
        ans[6]=cnt['x'-'a'];
        ans[7]=cnt['s'-'a']-cnt['x'-'a'];
        ans[5]=cnt['v'-'a']-ans[7];
        ans[4]=cnt['f'-'a']-ans[5];
        ans[3]=cnt['r'-'a']-ans[0]-ans[4];
        ans[8]=cnt['t'-'a']-ans[2]-ans[3];
        ans[1]=cnt['o'-'a']-ans[0]-ans[2]-ans[4];
        ans[9]=cnt['i'-'a']-ans[5]-ans[6]-ans[8];
        string res;
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<ans[i];j++)
            {
                res.push_back(i+48);
            }
        }
        return res;
    }
};