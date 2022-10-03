class Solution {
public:
    int minCost(string s, vector<int>& t) {
        int ans=0;
        for(int i=0;i<s.size();){
            char c=s[i];
            int sm=0;
            int mx=INT_MIN;
            while(i<s.size() && s[i]==c){mx=max(mx,t[i]);sm+=t[i];i++;}
            ans+=sm-mx;
            // cout<<sm<<" "<<mx<<" "<<ans<<endl;
        }
//         int ans=0;
//         int i=0;
//         for(auto ele: v){
//             if(ele==1){i++;continue;}
//             int p=ele;
//             sort(t.begin()+i, t.begin()+i+p);
            
//         }
        return ans;
    }
};