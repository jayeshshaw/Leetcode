class Solution {
public:
    
    static bool cmp(pair<float,vector<int>> a,pair<float,vector<int>> b){
        return a.first<b.first;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<float,vector<int>>> v;
        for(int i=0;i<points.size();i++){
                int x1=points[i][0],y1=points[i][1];
                float d=sqrt(pow(x1,2)+pow(y1,2));
                vector<int> vv(2);
                vv[0]=x1;vv[1]=y1;
                v.push_back({d,vv});
        }
        
        sort(v.begin(),v.end(),cmp);
        vector<vector<int>> ans;
        for(auto i: v){
            ans.push_back(i.second);
            k--;
            if(k==0)break;
        }
        return ans;
    }
};