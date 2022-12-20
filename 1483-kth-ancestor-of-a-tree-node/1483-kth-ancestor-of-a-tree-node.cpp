class TreeAncestor {
public:
    vector<vector<int>> up;
    vector<int> depth;
    TreeAncestor(int n, vector<int>& parent) {
        
        up.resize(n,vector<int> (20));
        depth.resize(n);
        parent[0]=0;
        for(int i=0;i<n;i++)up[i][0]=parent[i];
        for(int j=1;j<20;j++){
            for(int i=0;i<n;i++){ 
                up[i][0]=parent[i];
                if(i!=0)depth[i]=depth[parent[i]]+1;
                up[i][j]=up[up[i][j-1]][j-1];
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<20;j++){
        //         cout<<i<<" "<<j<<" -> "<<up[i][j]<<endl;
        //     }
        // }
    }
    
    int getKthAncestor(int node, int k) {
        if(depth[node]<k)return -1;
        for(int j=0;j<20;j++){
            if((k) &(1LL<<j)){
                node=up[node][j];
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */