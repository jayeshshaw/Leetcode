class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> a;
        for(int i=0;i<=s.size();i++)a.push_back(i);
        vector<int> ans;
        int l=0,r=a.size()-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='I')ans.push_back(a[l++]);
            else ans.push_back(a[r--]);
        }
        ans.push_back(l++);
        return ans;
    }
};