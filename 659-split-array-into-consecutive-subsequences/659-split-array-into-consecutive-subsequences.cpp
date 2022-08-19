class Solution {
public:
    static bool cmp(const vector<int>& a,const vector<int>& b){
        if(a[1]==b[1]){
            int as=a[1]-a[0]+1;
            int bs=b[1]-b[0]+1;
            return as>bs;
        }
        return a[1]>b[1]; 
    }
    bool isPossible(vector<int>& A) {
        multiset<vector<int>,bool(*)(const vector<int>&,const vector<int>&)> m(cmp);
        unordered_map<int, int> left, end;
        for (int i: A) {
            left[i]++;
        }
        for (int i: A) {
            if (left[i] == 0) continue;
            left[i]--;
            if (end[i - 1] > 0) {   
                end[i - 1]--;
                end[i]++;
            } else if (left[i + 1] > 0 && left[i + 2] > 0) {
                left[i + 1]--;
                left[i + 2]--;
                end[i + 2]++;
            } else {   
                return false;
            }
        }
        return true;
    }
    
};