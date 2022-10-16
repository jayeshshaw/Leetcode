class Solution {
public:
    
    int f(int ind,int d,vector<int> &v,vector<vector<int>> &dp){
        if(d==1){
            int ans=v[ind];
            for(int i=ind+1;i<v.size();i++)ans=max(ans,v[i]);
            return ans;
        }
        
        if(dp[ind][d]!=-1)return dp[ind][d];
        
        int ans=INT_MAX;
        int mx=INT_MIN;
        for(int i=ind;i<v.size()-d+1;i++){
            mx=max(mx,v[i]);
            ans=min(ans,mx+ f(i+1,d-1,v,dp));
        }
        return dp[ind][d]=ans;
    }
    
    int minDifficulty(vector<int>& v, int d) {
        int n=v.size();
        if(n<d)return -1;
        if(n==d)return accumulate(begin(v),end(v),0);
        
        vector<vector<int>> dp(n,vector<int> (d+1,-1));
        
        return f(0,d,v,dp);
    }
};