class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int add) {
        int n=rocks.size();
        vector<int> baki(n);
        for(int i=0;i<n;i++){
            baki[i]=capacity[i]-rocks[i];
        }
        sort(begin(baki),end(baki));
        int ans=0;
        for(int i=0;i<n && add>0;i++){
            if(baki[i]==0){ans++;continue;}
            if(add>=baki[i]){
                ans++;
                add-=baki[i];
            }
            else break;
        }
        return ans;
    }
};