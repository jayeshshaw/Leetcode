class Solution {
public:
    bool f(string &a, string &b, string &c, int i, int j, int k,vector<vector<vector<int>>> &dp){
        if(k==c.size())return true;
        
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        
        bool picka=false,pickb=false;
        if(i<a.size() && a[i]==c[k]){picka=f(a,b,c,i+1,j,k+1,dp);}
        if(j<b.size() && b[j]==c[k]){pickb=f(a,b,c,i,j+1,k+1,dp);}
        
        return dp[i][j][k]= picka or pickb;
    }
    
    
    bool isInterleave(string s1, string s2, string s3) {
        int i=0,j=0,k=0;
        vector<vector<vector<int>>> dp(s1.size()+1,vector<vector<int>> (s2.size()+1, vector<int> (s3.size()+1,-1)));
        if(s3.size()!=s1.size()+s2.size())return 0;
        return f(s1,s2,s3,i,j,k,dp);
    }
};