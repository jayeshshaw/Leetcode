class Solution {
public:    
    
    vector<int> getOrder(vector<vector<int>>& v) {
        int n=v.size();
        for(int i=0;i<n;i++)v[i].push_back(i);
        
        sort(begin(v),end(v));
        int t=0,i=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> ms;
        vector<int> ans;
        
        while(i<n){
            if(ms.size()==0 && t<v[i][0]){
                t=v[i][0];
                ms.push({v[i][1],v[i][2]});
                i++;
            }
            while(i<n && t>=v[i][0]){
                ms.push({v[i][1],v[i][2]});i++;
            }
            auto p=ms.top();
            ms.pop();
            ans.push_back(p.second);
            t+=p.first;
            
        }
        while(ms.size()>0){
            auto p=ms.top();
            ms.pop();
            ans.push_back(p.second);
        }
        return ans;
        
    }
};