class Solution {
public:
    
    int f(int i, int j, string &a, string &b, vector<vector<int>> &dp){
        
        
        if(i<0)return j+1;
        if(j<0)return i+1;

        if(dp[i][j]!=-1)return dp[i][j];

        if( a[i]==b[j])return dp[i][j]=f(i-1,j-1,a,b,dp);
        int repl=1+f(i-1,j-1,a,b,dp);
        int inse=1+f(i,j-1,a,b,dp);
        int del=1+f(i-1,j,a,b,dp);

        return dp[i][j]=min({repl,inse,del});
    }
    
    int minDistance(string a, string b) {
        vector<vector<int>> dp(a.size()+1,vector<int> (b.size()+1,0));
        
        for(int i=0;i<a.size()+1;i++)dp[i][0]=i;
        for(int j=0;j<b.size()+1;j++)dp[0][j]=j;
        
        
        for(int i=1;i<=a.size();i++){
            for(int j=1;j<=b.size();j++){
                if( a[i-1]==b[j-1])dp[i][j]=dp[i-1][j-1];
                else{
                    int repl=1+dp[i-1][j-1];
                    int inse=1+dp[i][j-1];
                    int del=1+dp[i-1][j];

                    dp[i][j]=min({repl,inse,del});
                }
                
            }
        }
        
        return dp[a.size()][b.size()];
        // return f(a.size()-1,b.size()-1,a,b,dp); 
    }
};