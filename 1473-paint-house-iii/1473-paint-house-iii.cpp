class Solution {
public:
    int f(int ind, int tar, int m, int n, int prevcol,vector<int>& houses, vector<vector<int>>& cost,vector<vector<vector<int>>> &dp){
        // cout<<n<<" ";
        if(ind==houses.size()){
            if(tar>0 || tar<0)return 1e9;
            return 0;
        }
        if(tar<0)return 1e9;
        
        // if(tar==0 && (houses[ind]==0 || houses[ind]-1==prevcol))
        //     return cost[ind][prevcol];
        // if(tar==0)return 1e9;
        
        
        if(dp[ind][prevcol+1][tar]!=-1)return dp[ind][prevcol+1][tar];
        
        
        if(houses[ind]!=0){
            if(houses[ind]-1==prevcol)
                return dp[ind][prevcol+1][tar]=f(ind+1,tar,m,n,prevcol,houses,cost,dp);
            else 
                return dp[ind][prevcol+1][tar]=f(ind+1,tar-1,m,n,houses[ind]-1,houses,cost,dp);
        }
        
        
        
        int ans=1e9;
        
        // cout<<n<<endl;
        for(int i=0;i<cost[ind].size();i++){
            int a;int tmp;
            if(prevcol==i)tmp=tar;
            else tmp=tar-1;
            
            a=f(ind+1,tmp,m,n,i,houses,cost,dp);
            // cout<<ind<<" "<<i<<endl;
            a+=cost[ind][i];
            ans=min(a,ans);
        }
        return dp[ind][prevcol+1][tar]=ans;
        
    }
    
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m+4, vector<vector<int>> (n+4, vector<int> (target+4,-1) ));
        int tmp= f(0,target,-1,m,n,houses,cost,dp);
        if(tmp>=1e9)return -1;
        return tmp;
    }
};