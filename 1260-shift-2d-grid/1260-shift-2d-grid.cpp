class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& g, int k) {
        int m=g.size(),n=g[0].size();
        if(m==1 &&n==1)return g;
        while(k--)
        {int t=g[m-1][n-1];
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(j==0 && i==0)break;
                if(j==0 && i!=0)g[i][j]=g[i-1][n-1];
                else g[i][j]=g[i][j-1];
            }
        }
        g[0][0]=t;}
        return g;
    }
};