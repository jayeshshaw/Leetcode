/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* s=head,*f=head;
        if(!s)return s;
        do{
            s=s->next;
            if(f->next && f->next->next)f=f->next->next;
            else return NULL;
        }while(s!=f);
        
        s=head;
        while(s!=f){
            s=s->next;
            f=f->next;
        }
        return s;
    }
};