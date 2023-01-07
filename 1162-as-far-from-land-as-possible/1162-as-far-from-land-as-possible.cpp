class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
	    vector<vector<int>> vis(n, vector<int> (m,0));
	    
	    queue<vector<int>> q;
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                q.push({i,j,0});
	                vis[i][j]=1;
	            }
	        }
	    }
	    
	    int delrow[]={-1,0,1,0};
	    int delcol[]={0,1,0,-1};
        int ans=-1;
	    
	    while(q.size()>0){
	        auto v=q.front();q.pop();
	        int row=v[0],col=v[1],steps=v[2];
            if(grid[row][col]==0)
	        ans=max(ans,steps);
	        
	        for(int i=0;i<4;i++){
	            int nrow=row+delrow[i];
	            int ncol=col+delcol[i];
	            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0){
	                q.push({nrow,ncol,steps+1});
	                vis[nrow][ncol]=1;
	            }
	        }
	        
	    }
        // int ans=INT_MIN;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){ans=max(ans,dist[i][j]);}
        // }
        return ans;
    }
};