class Solution {
public:
    int compress(vector<char>& v) {
        int count=0;
        int n=v.size();
        string s;
        for(int i=0;i<v.size();i++){
            if(i<n-1 && v[i]==v[i+1]){count++;continue;}
            count++;
            s.push_back(v[i]);
            if(count>1)
            s+=(to_string(count));
            count=0;
        }
        v.resize(s.size());
        for(int i=0;i<s.size();i++)v[i]=s[i];
        return s.size();
    }
};