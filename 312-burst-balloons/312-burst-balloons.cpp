class Solution {
public:
    
    int f(int i, int j, vector<int> &v,vector<vector<int>> &dp){
        if(i>j)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int ans=-1e9,score;
        for(int k=i;k<=j;k++){
            score= v[i-1]*v[k]*v[j+1] + f(i,k-1,v,dp) + f(k+1,j,v,dp);
            ans=max(score,ans);
        }
        return dp[i][j]=ans;
    }
    
    
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(),vector<int> (nums.size(),-1));
        return f(1,nums.size()-2,nums,dp);
    }
};