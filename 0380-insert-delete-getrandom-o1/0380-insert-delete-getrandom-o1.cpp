class RandomizedSet {
public:
    unordered_map<int,int> mp;
    vector<int> arr;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val))return 0;
        arr.push_back(val);
        
        mp[val] = arr.size()-1;
        return 1;
    }
    
    bool remove(int val) {
        if(mp.count(val)==0)return 0;
        
        int ind=mp[val];
        arr[ind]=arr[arr.size()-1];
        arr.pop_back();
        mp[arr[ind]]=ind;
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
         int rand_idx=rand()%arr.size();
         return arr[rand_idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */