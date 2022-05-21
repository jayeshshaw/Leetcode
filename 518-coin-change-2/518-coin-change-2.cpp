class Solution {
public:
    int dp[310][10010]; 
    
    int func(int a,vector<int> &v,int s){
        if(a==0)return 1;
        if(s<0)return 0;
        if(dp[s][a]!=-1)return dp[s][a];
        
        int ans=0;
        for(int i=0;i<=a;i+=v[s]){
              ans+= func(a-i,v,s-1);
        }
        return dp[s][a]= ans;
    }
    
    int change(int a, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        int ans=func(a,coins,coins.size()-1);
        return ans;
    }
};