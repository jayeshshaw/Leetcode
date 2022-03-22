class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        int t=0,l=0;
        int r=n-1,b=m-1;
        int d=1;
        vector<int> v;
        
        while(l<=r && t<=b){
            if(d==1){
                for(int i=l;i<=r;i++)v.push_back(mat[t][i]);
                d=2;t++;
            }
            
            else if (d==2){
                for(int i=t;i<=b;i++)v.push_back(mat[i][r]);
                d=3;r--;
            }
            
            else if (d==3){
                for(int i=r;i>=l;i--)v.push_back(mat[b][i]);
                d=4;b--;
            }
            
            else if (d==4){
                for(int i=b;i>=t;i--)v.push_back(mat[i][l]);
                d=1;l++;
            }
        }
        return v;
    }
};