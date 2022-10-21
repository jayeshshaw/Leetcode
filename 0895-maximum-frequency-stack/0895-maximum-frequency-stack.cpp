class FreqStack {
public:
    map<int,int> mp;
    map<int,stack<int>> mp2;
    int mx=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        mp[val]++;
        mp2[mp[val]].push(val);
        mx=max(mp[val],mx);
    }
    
    int pop() {
        int ans=mp2[mx].top();
        mp2[mx].pop();
        mp[ans]--;
        if(mp2[mx].size()==0)mx--;
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */