class Solution {
public:
    int dp[510][510]={-1};
    int dp_fn(int i, int j, string &s, string &t) {
        if(i == 0 || j == 0)    return 0;

        if(dp[i][j] != -1)  return dp[i][j];
        
        if(s[i - 1] == t[j - 1]) return dp[i][j] = 1 + dp_fn(i - 1, j - 1, s, t);
        return dp[i][j] = max(dp_fn(i - 1, j, s, t), dp_fn(i, j - 1, s, t));
    }
    int minDistance(string s, string t) {
        
        memset(dp, -1, sizeof(dp));
        
        return s.size() + t.size() - 2 * dp_fn(s.size(), t.size(), s, t);
    }
};