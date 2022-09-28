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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz=0;
        ListNode* t=head;
        while(t){
            sz++;
            t=t->next;
        }
        int target=sz-n;
        if(target==0){head=head->next;return head;}
        int abhi=1;
        t=head;
        while(abhi<target){
            abhi++;
            t=t->next;
        }
        t->next=t->next->next;
        return head;
        
        
        
    }
};