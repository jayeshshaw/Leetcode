class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        int i=d.size()-1;
        while(i>=0 && d[i]==9)d[i--]=0;
        if(i>=0)d[i]++;
        else d.insert (d.begin(), 1);
        return d;
        
    }
};