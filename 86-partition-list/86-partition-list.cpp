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
    ListNode* partition(ListNode* head, int p) {
        ListNode* l=new ListNode(),* r=new ListNode();
        ListNode* traversal=head;
        ListNode* left=l;
        ListNode* right=r;
        while(traversal!=NULL){
            if(traversal->val<p){
                ListNode* nxt=new ListNode(traversal->val);
                left->next=nxt;
                left=left->next;
            }
            else{
                ListNode* nxt=new ListNode(traversal->val);
                right->next=nxt;
                right=right->next;
            }
            traversal=traversal->next;
        }
        l=l->next;r=r->next;
        if(!l)return r;
        if(!r)return l;
        left->next=r;
        return l;
    }
};