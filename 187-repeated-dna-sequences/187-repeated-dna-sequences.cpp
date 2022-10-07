class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> mp;
        
        int i=0,j=9;
        while(j<s.size()){
            string a="";
            for(int i=j-9;i<=j;i++)a+=s[i];
            mp[a]++;
            j++;
        }
        vector<string> ans;
        for(auto i: mp){
            if(i.second>1)ans.push_back(i.first);
        }
        return ans;
    }
};