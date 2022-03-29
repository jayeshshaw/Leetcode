/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> v1,v2,v3;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        makevec1(l1);makevec2(l2);
        
        int i=v1.size()-1,j=v2.size()-1;
        int c=0;//carry
        
        reverse(v1.begin(),v1.end());
        reverse(v2.begin(),v2.end());
        
        while(i>=0 || j>=0 || c>0){
            if(i>=0)c+=v1[i];
            if(j>=0)c+=v2[j];
            v3.push_back((c%10));
            c=c/10;
            i--;j--;
        }      
        
        ListNode* head;
        
        ListNode* l=new ListNode;
        l->val=v3[0];
        head=l;
        
        ListNode* h=head;
        
        for(int i=1;i<v3.size();i++){
            ListNode* l=new ListNode;
            h->next=l;
            l->val=v3[i];
            h=h->next;
        }
            
            
            return head;     
        
    }
    
    void makevec1(ListNode* l){
        if(!l)return ;
        while(l){
            v1.push_back(l->val);l=l->next;
        }
    }
    void makevec2(ListNode* l){
        if(!l)return ;
        while(l){
            v2.push_back(l->val);l=l->next;
        }
    }
};