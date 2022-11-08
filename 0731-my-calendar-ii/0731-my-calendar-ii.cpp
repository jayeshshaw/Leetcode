class MyCalendarTwo {
public:
    map<int,int> m;
    MyCalendarTwo() {
        
    }
    
    bool book(int s, int e) {
        m[s]++,m[e]--;
        int ans=0,sm=0;
        for(auto i: m){
            sm+=i.second;
            ans=max(ans,sm);
            if(ans>2){
                m[s]--,m[e]++;
                return 0;
            }
        }
        return 1;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */