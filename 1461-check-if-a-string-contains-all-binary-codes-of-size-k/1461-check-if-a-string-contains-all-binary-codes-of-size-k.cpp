class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> st;
        int i=0,j=k-1;
        string p="";
        while(j<s.size()){
            p="";
            for(int ii=i;ii<=j;ii++)p+=s[ii];
            st.insert(p);
            i++;j++;
        }
        return st.size()==1<<k;
    }
};