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
    ListNode* middleNode(ListNode* head) {
        if(!head)return head;
        int k=1;
        ListNode* h=head;
        while(h){
            h=h->next;
            k++;
        }
        int p=1,kk;
        if(k%2==0)kk=k/2;
        else kk=(k/2)+1;
        while(p<kk){
            head=head->next;
            p++;
        }
        return head;
    }
};