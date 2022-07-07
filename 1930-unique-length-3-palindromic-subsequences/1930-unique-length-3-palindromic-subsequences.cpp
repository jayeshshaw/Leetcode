class Solution {
public:
    int disti(string s, int i, int j){
        set<char> st;
        for(int ind=i+1;ind<j;ind++)st.insert(s[ind]);
        return st.size();
    }
    int countPalindromicSubsequence(string ss) {
        int ans=0;
        map<char,vector<int>> m;
        for(int i=0;i<ss.size();i++){
            m[ss[i]].push_back(i);
        }
        
        for(auto i: m){
            int s=i.second[0],e=i.second[i.second.size()-1];
            // int number=i.second.size()-2-1;
            if(e-s>1){
                ans+=disti(ss,s,e);
            }
            // cout<<i.first<<" "<<s<<","<<e<<" -> "<<ans<<endl;
        }
                
        return ans;
    }
};