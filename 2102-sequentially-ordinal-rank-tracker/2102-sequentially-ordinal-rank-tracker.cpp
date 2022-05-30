class SORTracker {
private:
    bool check(const pair<int,string> &a,const pair<int,string> &b)
    {
        if(a.first*(-1)>b.first*(-1))
            return true;
        else if(a.first*(-1)<b.first*(-1))
            return false;
        else if(a.second<b.second)
            return true;
        return false;
    }
public:
    priority_queue<pair<int,string>> large;
    priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> small;
    int k=0;
    SORTracker() {
        
    }
    void add(string name, int score)
    {
        auto p=make_pair(-score,name);
        if(k>=large.size())
        {
            if(small.size()>0 and check(small.top(),p))
            {
                large.push(small.top());
                small.pop();
                small.push(p);
            }
            else
                large.push(p);
        }
        else
        {
            if(check(p,large.top()))
            {
                small.push(large.top());
                large.pop();
                large.push(p);
            }
            else
                small.push(p);
        }
    }
    
    string get() 
    {
        k++;
        string res=large.top().second;
        if(large.size()<=k and small.size())
        {
            large.push(small.top());
            small.pop();
        }
        return res;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */