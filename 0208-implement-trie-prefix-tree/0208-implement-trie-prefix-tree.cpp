class Trie {
public:
    unordered_map<string,int> s,sw;
    Trie() {
        
    }
    
    void insert(string word) {
        s[word]=1;
        string p="";
        for(auto i: word){
            p+=i;
            sw[p]=1;
        }
    }
    
    bool search(string word) {
        return s[word]!=0;
    }
    
    bool startsWith(string prefix) {
        return sw[prefix]!=0;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */