class Solution {
public:
    int minDeletions(string s) {
        sort(s.begin(),s.end());
        unordered_map<int,int> m;
        int ans=0;
        for(int i=0;i<s.size();){
            int p=0;char c=s[i];
            while(i<s.size() && s[i]==c){p++;i++;}
            int fq=p;bool done=false;
            while(fq>0){
                if(m[fq]==0){m[fq]=1,ans+=p-fq,done=true;break;}
                fq--;
            }
            if(!done) ans+=p;
        }
        return ans;
    }
};