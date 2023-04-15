class Solution {

private:
    vector<vector<int>> dp;
    int n,m;
    int f(int i, int k,  vector<vector<int>> &v){
        if(i==v.size())return 0;
        
        if(dp[i][k]!=-1)return dp[i][k];
        
        int kitna=0, ans=0;
        for(int j=0;j<v[i].size() && k>j;j++){
            kitna+=v[i][j];
            int abhi=f(i+1,k-j-1,v);
            ans=max(ans,abhi+kitna);
        }
        int abhi=f(i+1,k,v);
        ans=max(ans,abhi);
        
        return dp[i][k]=ans;
    }
    
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        dp.resize(1003, vector<int> (2005,-1));
        return f(0,k,piles);
        
    }
};