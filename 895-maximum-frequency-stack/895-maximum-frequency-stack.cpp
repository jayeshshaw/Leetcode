class FreqStack {
public:
    // vector<int> v;
    map<int,int> freq;
    map<int,stack<int>> mp;
    int mx=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        mp[freq[val]].push(val);
        mx=max(freq[val],mx);
    }
    
    int pop() {
        int k=mp[mx].top();
        mp[mx].pop();
        freq[k]--;
        if(mp[mx].size()==0)mx--;
        return k;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */