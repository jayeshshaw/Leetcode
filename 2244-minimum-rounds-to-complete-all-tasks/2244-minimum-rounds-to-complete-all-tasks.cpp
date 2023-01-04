class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        for(auto i: tasks)mp[i]++;
        
        int ans=0;
        for(auto i: mp){
            int ele=i.second;
            if(ele==1)return -1;
            ans+=ele/3;
            if(ele%3!=0)ans++;
        }
        return ans;
    }
};