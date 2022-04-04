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
    ListNode* swapNodes(ListNode* head, int k) {
        int n=0;
        ListNode* t=head;
        while(t){n++;t=t->next;}
        ListNode* p1=head,*p2=head;
        int i=k-1,j=n-k;
        while(i>0 || j>0){
            if(j>0){j--;p2=p2->next;}
            if(i>0){i--;p1=p1->next;}
        }
        int tt=p1->val;
        p1->val=p2->val;
        p2->val=tt;
        return head;
    }
};