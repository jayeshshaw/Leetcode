class Solution {
public:
    
    static bool cmp1(vector<int> a, vector<int> b){
        return (a[0] - a[1] < b[0] - b[1]);
    }
    int twoCitySchedCost(vector<vector<int>>& c) {
        int ans=0;
        int n=c.size()/2;
        sort(c.begin(),c.end(),cmp1);
        for(int i=0;i<n;i++)ans+=c[i][0];
        for(int i=n;i<2*n;i++)ans+=c[i][1];
        return ans;
    }
};