class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& m) {
        vector<vector<int>> ans(m[0].size(), vector<int> (m.size()));
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[0].size();j++)
                ans[i][j]=m[j][i];
        }
        return ans;
    }
};