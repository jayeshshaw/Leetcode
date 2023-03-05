class Solution {
private:
    // vector<int> dp;
//     int f(int ind, vector<int> &v){
//         if(ind==v.size()-1)return 0;
//         if(ind>v.size())return 1e9;
        
//         cout<<ind<<" ";
//         if(dp[ind]!=-1)return dp[ind];
        
//         int a=1e9,b=a,c=a;
//         for(int i=0;i<mp[v[ind]].size();i++){
//             int ele=mp[v[ind]][i];
//             if(ele!=ind)
//             c=min(c,1+f(ele,v));
//         }
//         if(ind>0)b=1+f(ind-1,v);
//         a=1+f(ind+1,v);
        
        
//         return dp[ind]=min({a,b,c});
        
//     }
    
public:
    int minJumps(vector<int>& v) {
        int n=v.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++)mp[v[i]].push_back(i);
        
        queue<vector<int>> q;
        q.push({0,0});
        vector<int> vis(n,0);
        vis[0]=1;
                
        while(q.size()>0){
            vector<int> vec=q.front();
            int a=vec[0],b=vec[1];
            // cout<<a<<"-> ";
            q.pop();
            if(a==n-1){return b;}
            
            if(a>0 && !vis[a-1]){
                vis[a-1]=1;
                q.push({a-1,b+1});
                // cout<<a-1<<" ";
            }
            
            if(a<n-1 && !vis[a+1]){
                vis[a+1]=1;
                q.push({a+1,b+1});
                // cout<<a+1<<" ";
            }
            
            for(auto i: mp[v[a]]){
                if(!vis[i] && i!=a){
                    vis[i]=1;
                    q.push({i,b+1});
                    // cout<<i<<" ";
                }
            }
            mp[v[a]].clear();
        }
        
        return -1;        
        
    }
};