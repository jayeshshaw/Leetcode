class TimeMap {
public:
    unordered_map<string,unordered_map<int,string>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].insert({timestamp,value});
    }
    
    string get(string key, int time) {
        while(time>=1){
            if(mp[key].find(time) != mp[key].end())return mp[key][time];
            time--;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */