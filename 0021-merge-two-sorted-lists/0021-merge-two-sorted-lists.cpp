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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode ans(INT_MIN);
        ListNode* last=&ans;
        
        while(l1 && l2){
            if(l1->val<l2->val)last->next=l1,l1=l1->next;
            else last->next=l2,l2=l2->next;
            last=last->next;
        }
        if(l1)last->next=l1;
        else if(l2)last->next=l2;
        
        return ans.next;
    }
};