class Solution {
public:
    string sortSentence(string s) {
        vector<string> v(11,"1");
        for(int i=0;i<s.size();i++){
            string p="";
            while(i<s.size() && s[i]!=' '){p+=s[i];i++;}
            int ind=p[p.size()-1]-'0';
            // cout<<p<<" ";
            p.pop_back();
            v[ind]=p;            
        }
        string ans="";
        for(int i=1;v[i]!="1";i++){
            ans+=v[i]+' ';
        }
        ans.pop_back();
        return ans;
    }
};