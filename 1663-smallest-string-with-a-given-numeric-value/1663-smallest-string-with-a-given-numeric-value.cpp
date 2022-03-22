class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans="";int t=n;
        for(int i=0;i<n;i++)ans.push_back('a');
        int i=n-1;
        while(t<k){
            ans[i--]='a'+min(25,k-t);
            t+=ans[i+1]-'a';
        }
        return ans;
    }
};