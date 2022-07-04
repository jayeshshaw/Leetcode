class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        
        vector<int> candy(n,1);
        for(int i=1;i<n;i++)
            if(ratings[i]>ratings[i-1])candy[i]=1+candy[i-1];
        for(int i=n-2;i>=0;i--)
            if(ratings[i]>ratings[i+1])candy[i]=max(1+candy[i+1],candy[i]);
        int ans=accumulate(candy.begin(),candy.end(),0);
        return ans;
    }
};