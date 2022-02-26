class Solution {
public:
    string reorganizeString(string s) {
        bool already=true;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1]){already=false;break;}
        }
        if(already)return s;
        
        unordered_map<char,int> mp;
        for(auto i: s)mp[i]++;
        int mx=INT_MIN; char m;
        
        for(auto i: mp){
            if(i.second>mx){
                mx=i.second;
                m=i.first;
            }
        }
        
        if(mx>(s.size()+1)/2)return "";
        
        string ans=s;
        
        int ind=0;
        while(mp[m]>0 && ind<s.size()){
            ans[ind]=m;
            ans[ind+1]='.';
            ind+=2;
            mp[m]--;
        }
        cout<<ans;
        
        
        
        for(auto i: mp){
            while(i.second>0){
                if(ind>=s.size())ind=1;
                ans[ind]=i.first;
                ind+=2;
                i.second--;
            }
        }
        return ans;
        
    }
};