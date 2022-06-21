class Solution {
public:
    int furthestBuilding(vector<int>& v, int bricks, int ladders) {
        multiset<int> s;
        int k;
        for(int i=0;i<v.size()-1;i++){
            k=v[i+1]-v[i];
            if(k>0) s.insert(k);
            if(s.size()>ladders){
                bricks-=*s.begin();
                s.erase(s.begin());
                if(bricks<0)return i;
            }
        }
        return v.size()-1;
    }
};