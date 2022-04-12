class Solution {
public:
    void gameOfLife(vector<vector<int>>& b) {
        
        int m=b.size(),n=b[0].size();
        vector<vector<int>> ans=b;
                
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                check(ans,b,b[i][j],i,j,m,n);
            }
        }
        b=ans;
    }
    
    void check(vector<vector<int>> &a,vector<vector<int>> b,int c,int x,int y,int m,int n){
        int dx[]={-1,1,0};
        int dy[]={-1,1,0};
        int o=0,z=0;
        for(auto i: dx){
            for(auto j: dy){
                if(x+i>=m || x+i<0 || y+j>=n || y+j<0 || (i==0 && j==0))continue;
                else if(b[x+i][y+j]==1)o++;
                else z++;
            }
        }
        // cout<<c<<" "<<o<<endl; 
        if(c==1){
            // cout<<x<<" "<<y<<endl;
            if(o<2 || o>3)a[x][y]=0;
        }
        if(c==0 && o==3)a[x][y]=1;
        // a[x][y]=o;
    }
};