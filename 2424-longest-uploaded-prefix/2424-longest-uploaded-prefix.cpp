class LUPrefix {
public:
    vector<int> v;
    int ind;
    LUPrefix(int n) {
        v.resize(n+1,0);
        v[0]=1;
        ind=1;
    }
    
    void upload(int video) {
        v[video]=1;
        while(ind<v.size() && v[ind]==1)ind++;
    }
    
    int longest() {
        return ind-1;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */