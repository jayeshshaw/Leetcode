class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=9;
        unordered_set<char> r[n];
        unordered_set<char> c[n];
        unordered_set<char> s[n];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                char t=board[i][j];
                if(t=='.')continue;
                int p=(i/3)*3+j/3;
                if(r[i].count(t) || c[j].count(t) || s[p].count(t))return false;
                
                r[i].insert(t);
                c[j].insert(t);
                s[p].insert(t);
            }
        }
        return true;
    }
};