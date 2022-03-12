/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    
    int findd(vector<Node*> a,Node* r){
        for(int i=0;i<a.size();i++){
            if(a[i]==r)return i;
        }
        return 0;
    }
    
    Node* copyRandomList(Node* head) {
        if(head==NULL)return NULL;
        vector<Node*> a,b;
        
        Node* t=head;
        Node* n=new Node(t->val);
        a.push_back(t);
        b.push_back(n);
        t=t->next;
        Node* c=n;
        while(t){
            Node* nn=new Node(t->val);
            a.push_back(t);
            b.push_back(nn);
            c->next=nn;
            c=c->next;
            t=t->next;
        }
        t=head;
        c=n;
        while(t){
            if(t->random!=NULL){
                int ind=findd(a,t->random);
                c->random=b[ind];
            }
            
            c=c->next;
            t=t->next;
        }
        return n;
    }
};