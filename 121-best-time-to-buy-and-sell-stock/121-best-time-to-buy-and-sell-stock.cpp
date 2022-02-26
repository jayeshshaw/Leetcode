class Solution {
public:
    int maxProfit(vector<int>& p) {
       int buy=p[0],profit=0;
        for(int i=1;i<p.size();i++){
            buy=min(buy,p[i]);
            profit=max(profit,p[i]-buy);
        }
        return profit;
    }
};