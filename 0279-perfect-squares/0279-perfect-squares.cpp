class Solution {
public:
    int ans=100;
    
    int f(int i,vector<int> &v,int sm,vector<vector<int>> &dp){
        if(sm==0)return 0;
        if(i==v.size())return 1e9;
        
        if(dp[sm][i]!=-1)return dp[sm][i];
        
        int a=1e9,b;
        if(sm-v[i]>=0)a= 1+f(i,v,sm-v[i],dp);
        
        b= f(i+1,v,sm,dp);
        return dp[sm][i]=min(a,b);
        
    }
    
    int numSquares(int n) {
        vector<int> v;
        for(int i=1;i<=100;i++){v.push_back(i*i);}
        reverse(begin(v),end(v));
        vector<vector<int>> dp(n+1,vector<int> (100,-1));
        return f(0,v,n,dp);
    }
};