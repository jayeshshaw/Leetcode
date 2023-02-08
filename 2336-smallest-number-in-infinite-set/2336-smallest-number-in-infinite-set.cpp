class SmallestInfiniteSet {
public:
    int i=1;
    set<int> m;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if(m.size()==0)return i++;
        int k=*m.begin();
        if(k<i){
            m.erase(m.begin());
            return k;
        }
        if(k==i){
            m.erase(m.begin());return i++;
        }
        auto it=m.find(i);
        if(it!=m.end())m.erase(it);
        return i++;
    }
    
    void addBack(int num) {
        m.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */