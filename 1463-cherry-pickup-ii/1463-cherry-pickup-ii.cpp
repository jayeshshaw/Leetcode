class Solution {
public:
    
    int f(int i,int j1,int j2, int n,int m, vector<vector<int>>& v,vector<vector<vector<int>>> &dp){
        // if(j1>=m || j1<0 || j2>=m || j2<0)return -1e8;
        if(i==n-1){
            if(j1==j2)return v[i][j1];
            return v[i][j1]+v[i][j2];
        }
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        int mx=-1e8;
        for(int p=-1;p<2;p++){
            for(int q=-1;q<2;q++){
                int newj1=j1+p,newj2=j2+q;
                if(newj1<0 || newj1>=m || newj2<0 || newj2>=m)continue;
                
                int ans=0;
                if(newj1==newj2)ans+=v[i][j2];
                else ans+=v[i][j1]+v[i][j2];
                ans+=f(i+1,newj1,newj2,n,m,v,dp);
                mx=max(mx,ans);
            }
        }
        return dp[i][j1][j2]= mx;
    }
   
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (m, vector<int> (m,-1)));
        return f(0,0,m-1,n,m,grid,dp);
    }
};