class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> vis(26,0),mp(26,-1);
        stack<char> ans;
        
        ans.push(s[0]);vis[s[0]-'a']=1;
        
        for(int i=0;i<s.size();i++)
            mp[s[i]-'a']=max(i,mp[s[i]-'a']);
        
        
        for(int i=0;i<s.size();i++){
            if(vis[s[i]-'a']==1)continue;
            while(ans.size()>0 && i<mp[ans.top()-'a'] && ans.top()>s[i])
                {vis[ans.top()-'a']=0;ans.pop();}
           ans.push(s[i]);vis[s[i]-'a']=1;
        }
        string res="";
        while(ans.size()>0){
            res+=ans.top();
            ans.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};