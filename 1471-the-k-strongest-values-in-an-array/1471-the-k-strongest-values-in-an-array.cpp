int m;
bool comp(int a,int b)
{
    return abs(a-m)==abs(b-m) ? a>b: abs(a-m)>abs(b-m);
}
class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        m=arr[(n-1)/2];
        sort(arr.begin(),arr.end(),comp);
        arr={arr.begin(),arr.begin()+k};
        return arr;
    }
};