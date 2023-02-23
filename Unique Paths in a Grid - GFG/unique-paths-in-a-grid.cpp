//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++



class Solution {
    int mod=1000000007;
    vector<vector<int>> dp;
    int f(int i,int j, vector<vector<int>> &v){
        if(i<0 || i>=v.size() || j<0 || j>=v[0].size() || v[i][j]==0)return 0;
        if(i==v.size()-1 && j==v[0].size()-1)return 1;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int ans=0;
        ans+=(f(i+1,j,v)%mod+f(i,j+1,v)%mod)%mod;
        return dp[i][j]= ans;
    }
  public:
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        // code here
        dp.resize(n,vector<int> (m,-1));
        return f(0,0,grid);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends