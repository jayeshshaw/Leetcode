class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int mn=1e9;
        for(auto i: prices){
            mn=min(mn,i);
            profit=max(profit,i-mn);
        }
        return profit;
    }
};