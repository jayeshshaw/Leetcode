//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
        
    void dfs(int r, int c, vector<vector<int>> &ans, int newCol,int iniCol){
        int n=ans.size(),m=ans[0].size();
        
        
        ans[r][c]=newCol;
        
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr=r+dx[i];
            int nc=c+dy[i]; 
            if(nr>=0 && nr<n && nc>=0 && nc<m && ans[nr][nc]==iniCol){
                dfs(nr,nc,ans,newCol,iniCol);
            }
        }
        
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int i, int j, int newColor) {
        vector<vector<int>> ans=image;
        int iniCol=ans[i][j];
        if(iniCol==newColor)return image;
        dfs(i,j,ans,newColor,iniCol);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends