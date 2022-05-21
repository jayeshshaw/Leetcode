class Solution {
public:
    int dp[10005];
    
    
    int compute(int a, vector<int> &v){
        if(a==0)return 0;
        if(dp[a]!=-1)return dp[a];
        int ans=INT_MAX;
        for(int i: v){
            if(a-i>=0)
                ans=min(ans+0ll,compute(a-i,v)+1ll);
        }
        return dp[a]=ans;
    }
    
    int coinChange(vector<int>& v, int a) {
        
        memset(dp,-1,sizeof(dp));
        int res= compute(a,v);
        return res==INT_MAX? -1: res;
    }
};