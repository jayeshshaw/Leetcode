class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]=i;
        }
        
        bool f=true;
        int n;
        for(int i=0;i<s.size();i++){
            
            // cout<<i<<" ";
            int mx=m[s[i]];
            int k=0;
            for(++i;i<=mx;i++){
                mx=max(mx,m[s[i]]);
                k++;
            }
            --i;
            // cout<<--i<<endl;
            ans.push_back(k+1);
        }
        return ans;
    }
};