class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        set<pair<int,int>> s;
        for(int i=0;i<mat.size();i++){
            int c=0;
            for(auto j: mat[i]){
                if(j==1)c++;
            }
            s.insert({c,i});
        }
        
         vector<int> ans;
        auto it=s.begin();
        while(k>0){
            ans.push_back(it->second);
            ++it;
            --k;
        }
        
       
        return ans;
    }
};