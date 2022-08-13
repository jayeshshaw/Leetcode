class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words){
        int w_size=words[0].size();
        
        int n=words.size();
        
        vector<int> ans;
        if(s.size()<n*w_size)return ans;
        
        for(int i=0;i<=s.size()-n*w_size;i++){
            
            unordered_map<string,int> mp;
            for(auto i: words)mp[i]++;
            
            int k=0;
            for(;k<words.size();k++){
                string ss=s.substr(i+k*w_size,w_size);
                
                if(mp[ss]>0)mp[ss]--;
                else break;
            }
            
            if(k==words.size())ans.push_back(i);
            
        }
        return ans;
    }
};