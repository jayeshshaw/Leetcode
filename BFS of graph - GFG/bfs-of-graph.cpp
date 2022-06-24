// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> v;
        vector<int> vis(V+1,0);
       
        queue<int> q;
        // for(int i=0;i<V;i++)
        // {
        int i=0;
            if(!vis[i])
            {
                q.push(i);
                vis[i]=1;
                while(!q.empty())
                {
                    int n=q.front();
                    q.pop();
                    v.push_back(n);
                    
                    for(auto it:adj[n])
                    {
                        if(!vis[it])
                        {
                            q.push(it);  
                            
                            vis[it]=1;
                        }
                    }
                    
                }
            }
        // }
        return v;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends