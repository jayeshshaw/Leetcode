class Solution {
public:
    
    
    int minRefuelStops(int target, int s, vector<vector<int>>& stations) {
        multiset<int, greater<int>> m;
        int ans=0;
        int max_reach=s;
        int ind=0;
        while(max_reach<target){
            while(ind<stations.size() && stations[ind][0]<=max_reach){
                m.insert(stations[ind++][1]);
            }
            if(m.size()<=0)return -1;
            
            max_reach+=*m.begin();
            m.erase(m.begin());
            ans++;
        }
        return ans;
    }
};