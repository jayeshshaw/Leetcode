class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string,int> mp;
        for(auto i: bank)mp[i]++;
        if(mp[end]==0)return -1;
        
        queue<string> q;
        q.push(start);
        int ans=0;
        
        while(!q.empty()){
            int s=q.size();
            while(s--){
                string ss=q.front();
                q.pop();
                if(ss==end)return ans;
                mp[ss]=0;
                
                string t;
                for(int i=0;i<8;i++){
                    t=ss;
                    t[i]='A';
                    if(mp[t]>0)q.push(t);
                    t[i]='C';
                    if(mp[t]>0)q.push(t);
                    t[i]='G';
                    if(mp[t]>0)q.push(t);
                    t[i]='T';
                    if(mp[t]>0)q.push(t);
                }
            }
                ans++;
        }
        return -1;
    }
};