class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans=0;
        vector<vector<int>> v(words.size(),vector<int> (26,0));
        int ind=0;
        for(auto i: words){
            for(auto j: i){
                v[ind][j-'a']++;
            }
            ind++;
        }
        
        // int ans=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                bool hoga=true;
                for(int k=0;k<words[i].size();k++){
                    if(v[j][words[i][k]-'a']!=0){hoga=false;break;}
                }
                if(hoga)ans=max(ans,(int)words[i].size()*(int)words[j].size());
            }
        }
        return ans;
    }
};