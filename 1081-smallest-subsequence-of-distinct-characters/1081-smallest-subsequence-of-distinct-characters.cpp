class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> vis(26,0),mp(26,-1);
        for(int i=0;i<s.size();i++)mp[s[i]-'a']=i;
        
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(vis[s[i]-'a']==1)continue;
            while(st.size()>0 && i<mp[st.top()-'a'] && st.top()>s[i])
                {vis[st.top()-'a']=0;st.pop();}
            st.push(s[i]);
            vis[s[i]-'a']=1;
        }
        string ans="";
        while(st.size()>0){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};