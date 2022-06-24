class Solution {
public:
    
    int f(int i, int pre, vector<int> &v,vector<vector<long>> &dp){
        if(i==v.size())return 0;
        
        if(dp[i][pre+1]!=-1)return dp[i][pre+1];
        
        int a=0,b=0;
        if(pre==-1 || v[i]> v[pre])a= 1 + f(i+1,i,v,dp);
        b=f(i+1,pre,v,dp);
        
        return dp[i][pre+1]= max(a,b); 
    }
    
    int lengthOfLIS(vector<int>& v) {
        vector<vector<long>> dp(v.size()+1,vector<long> (v.size()+1,0));
        
        for(int i=v.size()-1;i>=0;i--){
            for(int pre=i-1;pre>=-1;pre--){
                int a=0,b=0;
                if(pre==-1 || v[i]> v[pre])a= 1 + dp[i+1][i+1];
                b=dp[i+1][pre+1];

                dp[i][pre+1]= max(a,b);
            }
        }
        return dp[0][0];
        
        // return f(0,-1,v,dp);
    }
};