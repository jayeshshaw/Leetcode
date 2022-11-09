class StockSpanner {
public:
    stack<vector<int>> s;
    StockSpanner() {
        
    }
    
    int next(int p) {
        int ans=0;
        while(s.size()>0 && s.top()[0]<=p){
            ans+=s.top()[1];
            s.pop();
        }
        ans++;
        s.push({p,ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */