class Solution {
public:
    int closestMeetingNode(vector<int>& v, int node1, int node2) {
        unordered_map<int,int> distFrom1;
        int i=node1;
        int d=0;
        
        vector<int> vis(v.size(),0);
        
        while(i!=-1){
            if(vis[i]==1)break;
            vis[i]=1;
            // cout<<i<<" ";
            distFrom1[i]=d++;i=v[i];
        }
        // cout<<endl;
        i=node2;
        int dis=0;
        int ans=-1,mn=INT_MAX;
        
        for(auto &i: vis)i=0;
        
        while(i!=-1){
            if(vis[i]==1)break;
            vis[i]=1;
            
            // cout<<i<<" "; 
            if(distFrom1.find(i)==distFrom1.end()){i=v[i];dis++;continue;}
            int dist1=distFrom1[i];
            int abhi=max(dis,dist1);
            if(abhi<mn){mn=abhi;ans=i;}
            if(abhi==mn){ans=min(ans,i);}
            i=v[i];
            dis++;
        }
        return ans;
    }
};