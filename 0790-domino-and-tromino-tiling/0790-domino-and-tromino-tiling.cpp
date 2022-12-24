class Solution {
public:
    int mod=1000000007;
    vector<vector<int>> dp;
    long long f(int i,int khali, int n){
        if(i>n)return 0;
        if(i==n)return khali==0;
        
        if(dp[i][khali]!=-1)return dp[i][khali];
        
        long long ans=0;
        if(khali==0){
            ans+=f(i+1,0,n)%mod;
            ans+=f(i+2,0,n)%mod;
            ans+=2*f(i+2,1,n)%mod;
        }
        else{
            ans+=f(i+1,0,n)%mod;
            ans+=f(i+1,1,n)%mod;
        }
        return dp[i][khali]=ans%mod;
    }
    
    
    int numTilings(int n) {
        dp.resize(n+1,vector<int> (2,-1));
        return f(0,0,n);
    }
};