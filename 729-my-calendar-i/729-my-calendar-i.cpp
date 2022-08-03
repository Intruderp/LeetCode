class MyCalendar {
public:
    set<pair<int,int>> intervals;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) 
    {
        auto it=intervals.lower_bound({start+1,0});
        if(it!=intervals.end() and end>it->second)
            return false;
        intervals.insert({end,start});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */