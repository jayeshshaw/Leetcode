class Solution {
public:
    int shortestSequence(vector<int>& r, int k) {
        set<int> s;
        int start=0;
        int ans=1;
        while(1){
            s.clear();
            int number=0,max_ind=0;
            int i=start;
            while(i<r.size() && s.size()<k){
                if(s.find(r[i])==s.end()){
                    number++,s.insert(r[i]);
                    max_ind=max(i,max_ind);
                }
                i++;
            }
            if(number<k)return ans;
            start=max_ind+1,ans++;
            
        }
        return ans;
    }
};