class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        int n=s.size();
        
        for(int i=0;i<n;){
            if(st.size()==0){st.push(s[i++]);continue;}
            while(st.size()>0 && i<n && (st.top()==s[i]+32 || st.top()==s[i]-32)){st.pop();i++;}
            if(i<n)st.push(s[i++]);
        }
        string ans;
        while(st.size()>0){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),end(ans));
        return ans;
    }
};