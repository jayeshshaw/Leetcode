/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> v;
        if(!root)return v;
        queue<Node*> q;
        vector<int> p;
       
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
                Node* t=q.front();
              q.pop();
            if(t==NULL){
                v.push_back(p);
                p.resize(0);
                if (q.size() > 0) {
                    q.push(NULL);
                }
                
            }
             else{p.push_back(t->val);
                  for(auto it:t->children)
            {if(it)q.push(it);}}
          
                
        }
        return v;
    }
};