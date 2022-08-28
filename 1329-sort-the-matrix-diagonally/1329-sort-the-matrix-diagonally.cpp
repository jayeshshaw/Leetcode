class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<int> v;
        int n=mat.size();
        int m=mat[0].size();
        int i=0;
        for(int j=0;j<m;j++){
            int row=i,col=j;
            while(col<m && row<n){
                v.push_back(mat[row][col]);
                col++,row++;
            }
            sort(begin(v),end(v));
            row=i,col=j;
            int ind=0;
            while(col<m && row<n){
                mat[row][col]=v[ind++];
                col++,row++;
            }
            v.resize(0);
        }
        int j=0;
        for(int i=0;i<n;i++){
            int row=i,col=j;
            while(row<n && col<m){
                v.push_back(mat[row][col]);
                col++;row++;
            }
            sort(begin(v),end(v));
            row=i,col=j;
            int ind=0;
            while(col<m && row<n){
                mat[row][col]=v[ind++];
                row++;col++;
            }
            v.resize(0);
        }        
        return mat;
    }
};