class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans=-1;
        int n=gas.size();
        for(int i=0;i<n;i++){
            int cnt=0;
            int start=i;
            int gass=gas[i];
            while(gass>=cost[i%n] && cnt<n)gass-=cost[i%n],i++,cnt++,gass+=gas[i%n];
            cout<<start<<" "<<cnt<<endl;
            if(cnt==n){ans=start;break;}
        }
        return ans;
    }
};