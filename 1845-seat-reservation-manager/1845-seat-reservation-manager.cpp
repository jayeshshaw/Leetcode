class SeatManager {
public:
    vector<int> v;
    set<int> s;
    bool filled;
    SeatManager(int n) {
        for(int i=1;i<=n;i++)s.insert(i);
    }
    
    int reserve() {
        auto it=s.begin();
        int p=*it;
        s.erase(it);
        return p;
    }
    
    void unreserve(int ss) {
        s.insert(ss);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */