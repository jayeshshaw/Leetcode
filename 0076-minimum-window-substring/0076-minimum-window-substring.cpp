class Solution {
public:
    
    bool isitok(unordered_map<char,int> &a, unordered_map<char,int> &b){
        bool ok=true;
        for(int i=0;i<26;i++){
            if(a['A'+i]>b['A'+i]){ok=false;break;}
        }
        for(int i=0;i<26;i++){
            if(a['a'+i]>b['a'+i]){ok=false;break;}
        }
        return ok;
    }
    
    string minWindow(string s, string t) {
        unordered_map<char,int> a;
        for(auto i: t)a[i]++;
        
        int l=0,r=0;
        string ans=s;
        unordered_map<char,int> b;
        while(r<s.size()){
            b[s[r]]++;
            while(isitok(a,b) && l<=r){
                if(r-l+1<ans.size()){
                    ans="";
                    for(int i=l;i<=r;i++)ans+=s[i];
                }
                b[s[l]]--;l++;
            }
            r++;
        }
        for(auto &i: b)i.second=0;
        for(auto i: ans){
            b[i]++;
        }
        if(!isitok(a,b))return "";
        return ans;
    }
};