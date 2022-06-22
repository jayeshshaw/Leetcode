class Solution {
public:
    string shortestCommonSupersequence(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector<int> (p.size()+1,0));
    
        for(int i=0;i<s.size();i++)dp[i][0]=0;
        for(int j=0;j<p.size();j++)dp[0][j]=0;

        for(int i=1;i<s.size()+1;i++){
            for(int j=1;j<p.size()+1;j++){
                if(s[i-1]==p[j-1])dp[i][j]= 1+dp[i-1][j-1];
                else
                dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        string ans="";
        int i=s.size(),j=p.size();
        while(i>0 && j>0){
            if(s[i-1]==p[j-1]){
                ans+=s[i-1];
                i--;j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){i--;ans+=s[i];}
            else {j--;ans+=p[j];}
        }
        while(i>0)ans+=s[--i];
        while(j>0) ans+=p[--j];
        reverse(ans.begin(),ans.end());
        return ans;
    }
};