class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int> mp;
        for(auto i: words)mp[i]++;
        
        vector<vector<string>> v(500+1);
        int frq;
        // set<int, greater<int>> st;
        for(auto i: mp){
            // st.insert(i.second);
            v[i.second].push_back(i.first);
            // if(st.size()>k)st.erase(st.begin());
        }
        
        vector<string> ans;
        
        for(int i=500;i>=0;i--){
            sort(begin(v[i]),end(v[i]));
            for(auto ele: v[i]){
                if(k<=0)break;
                k--;
                ans.push_back(ele);
            }
            if(k<=0)break;
        }
        // sort(begin(ans),end(ans));
        return ans;
        
        
//       unordered_map<string,int> m;
        
//         vector<string> we;
//         for(auto i:words)
//         {
//             m[i]++;
//         }
//          vector<pair<string,int>>v(m.begin(),m.end());;
        
//         sort(v.begin(),v.end(), cmp);
//         for(auto i:v)
//         {
//             we.push_back(i.first);
//             k--;
//             if(k==0) break;
//         }
//         sort(we.begin(),we.end());
        
//         return we;
        
    }
};