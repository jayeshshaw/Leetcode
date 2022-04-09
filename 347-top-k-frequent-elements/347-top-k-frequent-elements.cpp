class Solution {

public:
      static bool cmp(pair<int, int>& a,
                 pair<int, int>& b)
        {
            return a.second > b.second;
        }
       vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> v;
        int n=nums.size();
        unordered_map<int,int> mp;
         
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        vector<pair<int,int>> pr(mp.begin(),mp.end());
        sort(pr.begin(),pr.end(),cmp);
        for(int i=0;i<min(k,(int)(nums.size()));i++)
        {
           v.push_back(pr[i].first);
        }
        return v;
    }
};