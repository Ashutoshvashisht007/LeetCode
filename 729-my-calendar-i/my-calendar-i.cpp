class MyCalendar {
public:
    MyCalendar() {
        
    }
    map<int,int> mp;
    bool book(int start, int end) {
        auto upper = mp.upper_bound(start);
        if(upper != mp.end() && (*upper).second < end){
            return false;
        }
        mp[end] = start;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */