class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        for(int i=0;i<m;i++){
            int j=0;
            int v=mat[i][j];
            int a=i;
            while(j<n && a<m){
                if(mat[a][j]!=v)return 0;
                j++;a++;
            }
        }
        
        for(int j=1;j<n;j++){
            int a=0,b=j;
            int v=mat[a][b];
            while(a<m && b<n){
                if(mat[a][b]!=v)return 0;
                a++;b++;
            }
        }
        return 1;
    }
};