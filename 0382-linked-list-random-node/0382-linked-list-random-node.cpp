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
    int s=0;
    ListNode* h,*t;
    Solution(ListNode* head) {
        h=head;
        t=head;
        while(t){s++;t=t->next;}
    }
    
    int getRandom() {
        int k=rand()%s;
        t=h;
        while(k--){
            t=t->next;
        }
        return t->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */