class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        vector<string> v;
        int i=0;
        
        for(;i<n;i++){
            while(i<n && s[i]==' ')i++;
            if(i>=n)break;
            string p;
            while(i<n && s[i]!=' ')p+=s[i++];
            v.push_back(p);            
        }
        s.erase();
        for(int i=v.size()-1;i>=0;i--)s+=v[i],s+=" ";
        s.pop_back();
        return s;
    }
};