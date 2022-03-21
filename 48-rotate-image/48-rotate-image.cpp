class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int m=mat.size();
        for(int i=0;i<m;i++){
            for(int j=0;j<i;j++){
                int temp=mat[i][j];
                mat[i][j]=mat[j][i];
                mat[j][i]=temp;
            }
        }
        int n=mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n/2;j++){
                int t=mat[i][j];
                mat[i][j]=mat[i][n-j-1];
                mat[i][n-j-1]=t;
            }
        }
        
    }
};