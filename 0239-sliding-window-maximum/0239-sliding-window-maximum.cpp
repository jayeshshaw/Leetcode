class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        multiset<int, greater<int>> ms;
        int n=v.size();
        for(int i=0;i<k;i++){
            ms.insert(v[i]);
        }
        vector<int> ans;
        ans.push_back(*ms.begin());
        int j=0;
        for(int i=k;i<n;i++){
            auto it=ms.find(v[j++]);
            ms.erase(it);
            ms.insert(v[i]);
            ans.push_back(*ms.begin());
        }
        return ans;
    }
};