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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev,*curr,*h;
        prev=NULL,curr=head,h=head;
        while(h!=NULL){
            h=h->next;
            curr->next=prev;
            prev=curr;
            curr=h;
        }
        return prev;
    }
};