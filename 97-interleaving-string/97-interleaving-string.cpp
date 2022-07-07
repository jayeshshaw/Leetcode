class Solution {
public:
    bool f(string &a, string &b, string &c, int i, int j,vector<vector<int>> &dp){
        if(i+j==c.size())return true;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        bool picka=false,pickb=false;
        if(i<a.size() && a[i]==c[i+j]){picka=f(a,b,c,i+1,j,dp);}
        if(j<b.size() && b[j]==c[i+j]){pickb=f(a,b,c,i,j+1,dp);}
        
        return dp[i][j]= picka or pickb;
    }
    
    
    bool isInterleave(string s1, string s2, string s3) {
        int i=0,j=0,k=0;
        vector<vector<int>> dp(s1.size()+1,vector<int> (s2.size()+1,-1));
        if(s3.size()!=s1.size()+s2.size())return 0;
        return f(s1,s2,s3,i,j,dp);
    }
};