class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& p) {
        if(!p.size())return 0;

        sort(p.begin(),p.end(),cmp);
        
        for(auto i: p)cout<<i[0]<<" "<<i[1]<<"   ";
        int ans=1;
        int last_arrow=p[0][1];
        
        for(int i=1;i<p.size();i++){
            if(p[i][0]<=last_arrow)continue;
            
            ans++;
            last_arrow=p[i][1];
        }
        return ans;
    }
};