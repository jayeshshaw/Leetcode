class Solution {
public:
    unordered_map<string,vector<string>> mp;
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        for(auto i: products){
            string s="";
            for(int j=0;j<i.size();j++){
                s+=i[j];
                mp[s].push_back(i);
            }
        }
        vector<vector<string>> ans;
        
        string s="";
        for(int j=0;j<searchWord.size();j++){
            s+=searchWord[j];
            vector<string> v= mp[s];
            ans.push_back({});
            sort(begin(v),end(v));
            
            for(int i=0;i<min((int)v.size(),3);i++){
                ans[j].push_back(v[i]);
            }
            
        }
        return ans;
    }
};