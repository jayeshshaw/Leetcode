class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        for(int i=0;i<s.size();i++){
            while(i<s.size() && s[i]==' ')i++;
            if(i>=s.size())break;
            
            int j=i;
            string p="";
            while(j<s.size() && s[j]!=' ')p+=s[j++];
            v.push_back(p);
            i=j;
        }
        s="";
        for(int i=v.size()-1;i>=0;i--)s+=v[i]+' ';
        s.pop_back();
        return s;
    }
};