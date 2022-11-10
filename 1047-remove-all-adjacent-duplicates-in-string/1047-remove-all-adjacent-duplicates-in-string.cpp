class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        int n=s.size();
        for(int i=0;i<n;){
            if(st.size()==0){st.push(s[i++]);continue;}
            if(st.size()>0 && i<n && st.top()==s[i]){
            while(st.size()>0 && i<n && st.top()==s[i]){
                st.pop();i++;
            }
            }
            else{
                if(i<n)st.push(s[i++]);
                else i++;
            }
            
        }
        string ans="";
        while(st.size()>0){
            ans+=st.top();
            st.pop();
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};