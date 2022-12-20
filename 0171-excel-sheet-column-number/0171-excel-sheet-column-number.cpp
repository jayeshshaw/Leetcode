class Solution {
public:
    int titleToNumber(string s) {
        int ans=0;
        int n=s.size();
        for(int i=n-1;i>=0;i--){
            int abhi=s[i]-'A'+1;
            ans+=pow(26,(n-i-1))*abhi;
        }
        return ans;
        
    }
};