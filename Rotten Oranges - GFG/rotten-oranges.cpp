//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct node{
    int x, y,time;
    node(int _x,int _y,int _time){
        x=_x;y=_y;time=_time;
    }
};

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& g) {
        
        int m=g.size();
        int n=g[0].size();
        
        int total=0;
        queue<node> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]==2) {q.push(node(i,j,0));}
                if(g[i][j]!=0)total++;
            }
            
        }
        int ans=0;
            
        while(!q.empty()){
            int x=q.front().x;
            int y=q.front().y;
            int time=q.front().time;
            q.pop();
            total--;
            ans=max(ans,time);
            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};
            
            for(int i=0;i<4;i++){
                int newx=x+dx[i];
                int newy=y+dy[i];
                
                if(newx>=0 && newx<m && newy>=0 && newy<n && g[newx][newy]==1 ){
                    g[newx][newy]=2;
                    q.push(node(newx,newy,time+1));
                    
                }
            }
        }
        if(total==0)return ans;
        return -1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends