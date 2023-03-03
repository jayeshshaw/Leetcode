class Solution {
public:
    int strStr(string a, string b) {
        if(a.size()<b.size())return -1;
        string s;
        for(int i=0;i<a.size()-b.size()+1;i++){
            s=a.substr(i,b.size());
            if(s==b)return i;
        }
        return -1;
    }
};