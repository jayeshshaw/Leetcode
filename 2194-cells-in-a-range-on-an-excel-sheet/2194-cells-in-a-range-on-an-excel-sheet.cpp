class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ans;
        char c1=s[0],c2=s[3];
        int r1=s[1]-'0',r2=s[4]-'0';
        for(char i=c1;i<=c2;i++){
            for(int j=r1;j<=r2;j++){
                string s=i+to_string(j);
                ans.push_back(s);
            }
        }
        return ans;
    }
};