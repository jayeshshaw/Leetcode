class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int m=mat.size();
        for(int i=0;i<m;i++){
            for(int j=0;j<i;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
        for(int i=0;i<m;i++){
            reverse(begin(mat[i]),end(mat[i]));
        }
        
    }
};