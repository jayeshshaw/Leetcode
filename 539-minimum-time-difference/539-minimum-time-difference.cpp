class Solution {
public:
    int findMinDifference(vector<string>& g) {
        vector<int> v;
        for(auto s: g){
            int hr=(s[0]-'0')*10+(s[1]-'0');
            int min=(s[3]-'0')*10+(s[4]-'0');
            int time=hr*60+min;
            v.push_back(time);
            v.push_back(24*60+time);
        }
        
        int ans=INT_MAX;
        sort(v.begin(),v.end());
        for(int i=1;i<v.size();i++){
            ans=min(ans,v[i]-v[i-1]);
        }
        return ans;
    }
};