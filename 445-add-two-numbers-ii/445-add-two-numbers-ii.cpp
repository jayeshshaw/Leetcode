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
public:vector<int> v1,v2,v3;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        makevec(1,l1);makevec(2,l2);
        
        int i=v1.size()-1,j=v2.size()-1,c=0;
        while(i>=0|| j>=0 ||c>0){
            if(i>=0)c+=v1[i--];
            if(j>=0)c+=v2[j--];
            v3.push_back(c%10);c/=10;
        }
        // reverse(v3.begin(),v3.end());
        ListNode* head;
        ListNode* l=new ListNode;
        l->val=v3[v3.size()-1];
        
        head=l;
        ListNode* h=head;
        
        for(int i=v3.size()-2;i>=0;i--){
             ListNode* l=new ListNode;
            h->next=l;
            l->val=v3[i];
            h=h->next;
        }
        
        return head;
    }
    
    void makevec(int n,ListNode* l){
        vector<int> t;
        while(l){
            t.push_back(l->val);
            l=l->next;
        }
        n==1?v1=t:v2=t;
        
    }
};