class Solution {
public:
    int f(int i, vector<int> &v, int buy, int moves, vector<vector<vector<int>>> &dp){

        if(i==v.size() || moves==0)return 0;
        
        if(dp[i][buy][moves]!=-1)return dp[i][buy][moves];

        if(buy==1)
            return dp[i][buy][moves]= max(-v[i]+f(i+1,v,0,moves,dp),f(i+1,v,1,moves,dp));
        else
            return dp[i][buy][moves]= max(v[i]+f(i+1,v,1,moves-1,dp), f(i+1,v,0,moves,dp));
    }

    int maxProfit(vector<int>& v) {
        vector<vector<vector<long>>> dp(v.size()+1,vector<vector<long>> (2,vector<long> (3,0)));
        // return f(0,prices,1,2,dp);
        
        for(int i=v.size()-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                for(int moves=1;moves<3;moves++){
                    if(buy==1)
                        dp[i][buy][moves]= max(-v[i]+dp[i+1][0][moves],dp[i+1][1][moves]);
                    else
                        dp[i][buy][moves]= max(v[i]+dp[i+1][1][moves-1], dp[i+1][0][moves]);
                }
            }
        }
        return dp[0][1][2];
    }
};