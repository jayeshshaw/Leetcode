class Solution {
public:
    bool ispalin(string &s,int i,int j){
        while(i<j){
            if(s[i++]!=s[j--])return 0;
        }
        return 1;
    }
    
    int f(int i,int j, string &s, int &k, vector<vector<int>> &dp){
        if(i>=s.size() || j>=s.size())return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int a=f(i+1,j+1,s,k,dp);
        int b=0;
        int c=f(i,j+1,s,k,dp);
        if(ispalin(s,i,j))b=f(j+1,j+k,s,k,dp)+1; 
        
        return dp[i][j]=max({a,b,c});
    }
    
    int maxPalindromes(string s, int k) {
        int ans=0;
        int n=s.size();
        string p=s;
        sort(begin(p),end(p));
        if(p[0]==p[n-1])return n/k;
        if(k==1)return n;
        vector<vector<int>> dp(2005,vector<int> (2005,-1));
        return f(0,k-1,s,k,dp);
    }
    
    
    // THE ABOVE CODE GIVES "TLE" IDK WHY, TC=N*N, SC=N*N
    
    // int maxPalindromes(string s, int k) {
    //     int ans=0;
    //     int n=s.size();
    //     if(k==1)return n;
    //     vector<vector<int>> dp(2005,vector<int> (2005,-1));
    //     return f(0,k-1,s,k,dp);
    // }
  
};