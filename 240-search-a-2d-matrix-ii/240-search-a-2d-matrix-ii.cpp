class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        int i=0,j=m[0].size()-1;
        while(i<m.size() && j>=0){
            // cout<<i<<" "<<j<<endl;           THIS LINE GIVES TLE
            if(m[i][j]==target)return true;
            else if(m[i][j]>target)j--;
            else i++;
        }
        return false;
    }
};