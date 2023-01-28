class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& q) {
        vector<vector<int>> v(n, vector<int> (n,0));
        for(auto i: q){
            for(int row=i[0];row<=i[2];row++){
                v[row][i[1]]++;
                if(i[3]<n-1)v[row][i[3]+1]--;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                v[i][j]+=v[i][j-1];
            }
        }
        return v;
    }
};