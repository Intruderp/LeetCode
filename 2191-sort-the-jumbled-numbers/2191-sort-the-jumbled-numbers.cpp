vector<int> m;
int convert(int a)
{
    int res=0,p=1;
    while(true)
    {
        res+=(m[a%10])*p;
        a/=10;
        if(a==0)
            break;
        p*=10;
    }
    return res;
}
bool comp(int &a,int &b)
{
    int x=convert(a),y=convert(b);
    return x<y;
}
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums)
    {
        m=mapping;
        sort(nums.begin(),nums.end(),comp);
        return nums;
    }
};