class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.size();
        int ones=0,ans=0;
        for(auto i: s){
            if(i=='0')ans++;
            else ones++;
            ans=min(ans,ones);
        }
        return ans;
    }
};