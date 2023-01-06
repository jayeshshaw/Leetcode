class Solution {
public:
    
    
    int maxIceCream(vector<int>& costs, int coins) {
        sort(begin(costs),end(costs));
        int ans=0,n=costs.size();
        for(int i=0;i<n && coins>0;i++){
            if(coins<costs[i])break;
            coins-=costs[i];
            ans++;
        }
        return ans;
    }
};