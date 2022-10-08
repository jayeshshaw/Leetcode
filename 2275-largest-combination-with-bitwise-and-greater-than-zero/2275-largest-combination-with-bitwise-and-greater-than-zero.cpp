class Solution {
public:
//     int pick,npick,ans=0;
//     int knapsack(vector<int>& v, int n,int nd,int tmp,int **dp){
//         if(n<0 && nd>0){ans=max(ans,tmp);return ans-1;}
//         if(n<0) return -1;
        
//         if(dp[n][tmp]!=-1)return dp[n][tmp];
       
//        if(nd==-1){
//            pick=1+ knapsack(v,n-1,v[n],1,dp);
//            npick= knapsack(v,n-1,nd,0,dp);
//        }
//         else{
//            pick=1+ knapsack(v,n-1,nd&v[n],tmp+1,dp);
//             npick= knapsack(v,n-1,nd,tmp,dp);
//         }
//         return dp[n][tmp]=max(pick,npick);
        
//     }
    int largestCombination(vector<int>& v) {
        // int n=c.size();
        // int** dp;
        // dp = new int*[n];
        // for (int i = 0; i < n; i++)
        // dp[i] = new int[n];
        // for (int i = 0; i < n; i++)
        // for (int j = 0; j < n; j++)
        //     dp[i][j] = -1;
        // return knapsack(c,c.size()-1,-1,0,dp);
        
        
        vector<int> bits(32,0);
        for(auto ele: v){
            int i=0;
            while(i<32){
                if(ele &(1<<i))bits[i]++;
                i++;
            }
        }
        int ans=0;
        for(auto i: bits)ans=max(i,ans);
        return ans;
    }
};