class Solution {
public:
    
    int f(int i, int j, vector<int>& s, vector<int>& p,vector<vector<int>> &dp){
        if(i<0 || j<0)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==p[j])return dp[i][j]= 1+f(i-1,j-1,s,p,dp);
        
        return  dp[i][j]=  max(f(i-1,j,s,p,dp),f(i,j-1,s,p,dp));
    }
    
    int lengthOfLIS(vector<int>& s) {
        vector<int> p=s;
        sort(p.begin(),p.end());
        for(int i=1;i<p.size();i++){
            while(i>0 && i<p.size() && p[i]==p[i-1])p.erase(p.begin()+i);
        }
        vector<vector<int>> dp(s.size()+1,vector<int> (p.size()+1,-1));
        return f(s.size()-1, p.size()-1,s,p,dp);
    }
};