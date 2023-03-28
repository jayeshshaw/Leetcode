class Solution {
private:
    vector<vector<int>> dp;
    int f(int ind, int allowed, vector<int>& days, vector<int>& costs){
        if(ind>=days.size())return 0;
        
        if(dp[ind][allowed]!=-1)return dp[ind][allowed];
        
        if(allowed>=days[ind])return dp[ind][allowed]=f(ind+1,allowed,days,costs);
        
        
        int a=costs[0]+f(ind+1,days[ind],days,costs);
        int b=costs[1]+f(ind+1,days[ind]+6,days,costs);
        int c=costs[2]+f(ind+1,days[ind]+29,days,costs);
        return dp[ind][allowed]=min({a,b,c});
        
        
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(366, vector<int> (400,-1));
        return f(0,0,days,costs);
    }
};