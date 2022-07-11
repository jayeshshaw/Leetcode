class Solution {
public:
    
    int f(int i,int j, vector<int> &v,vector<vector<int>> &dp){
        if(i>j)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int ans=1e9,cost;
        for(int k=i;k<=j;k++){
            cost=v[j+1]-v[i-1]+
                f(i,k-1,v,dp)+f(k+1,j,v,dp);
            ans=min(cost,ans);
        }
        return dp[i][j]=ans;
    }  
     
    
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(cuts.size()+1,vector<int> (cuts.size(),-1));
        return f(1,cuts.size()-2,cuts,dp);
    }
};