class Solution {
public:
    int lastStoneWeight(vector<int>& s) {
        // sort(s.begin(),s.end());
        int a,b;
        while(s.size()>1){
            sort(s.begin(),s.end());
            a=s.size()-1;
            b=s.size()-2;
            if(s[a]==s[b]){s.pop_back();s.pop_back();}
            else {int k=s[a]-s[b];s.pop_back();s.pop_back();s.push_back(k);}
        }
        return s.size()>0? s[0]:0;
    }
};