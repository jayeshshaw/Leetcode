class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        int i=0;int t=1;
        while(i<s.size()){
            if(st.size()==0 || st.top().first!=s[i]){st.push({s[i++],1});continue;}
            
            pair<char,int> p=st.top();
            if(p.first==s[i]){
                if(p.second==k-1){
                    int pp=k-1;
                    while(pp--){st.pop();}
                }
                else{
                    st.push({s[i],p.second+1});
                }
            }
            i++;
        }
        string ans="";
        while(st.size()>0){
            ans+=st.top().first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};