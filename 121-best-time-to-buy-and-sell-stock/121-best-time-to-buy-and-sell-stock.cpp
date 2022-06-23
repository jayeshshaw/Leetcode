class Solution {
public:
    int maxProfit(vector<int>& p) {
        int cost=p[0],pr=0;
        for(int i=1;i<p.size();i++){
            pr=max(pr,p[i]-cost);
            cost=min(cost,p[i]);
        }
        return pr;
    }
};