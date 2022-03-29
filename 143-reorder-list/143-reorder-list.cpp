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
    void reorderList(ListNode* head) {
        vector<int> v;
        ListNode* t=head;
        while(t){
            v.push_back(t->val);
            t=t->next;
        }
        t=head;
        int i=0,j=v.size()-1;
        while(t){
            t->val=v[i++];
            t=t->next;
            if(t){
                t->val=v[j--];
                t=t->next;
            }
        }
    }
};