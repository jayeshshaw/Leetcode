struct Node{
    Node * links[26];
    bool flag;
    
    bool contains(char c){
        return links[c-'a']!=NULL;
    }
    
    void put(char c,Node* node){
        links[c-'a']=node;
    }
};

class Trie {
private: Node* root=NULL;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->contains(word[i])){
                node->put(word[i],new Node());
            }
            node=node->links[word[i]-'a'];
        }
        node->flag=true;
    }
    
    bool search(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->contains(word[i])){
                return false;
            }
            node=node->links[word[i]-'a'];
        }
        return node->flag==true;
    }
    
    bool startsWith(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->contains(word[i])){
                return false;
            }
            node=node->links[word[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */