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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)return head;
        vector<int> v;
        ListNode* l=head;
        while(l){
            v.push_back(l->val);
            l=l->next;
        }
        int n=v.size();
        reverse(v.begin(),v.end());
        reverse(v.begin(),v.begin()+k%n);
        reverse(v.begin()+k%n,v.end());
        l=head;
        int i=0;
        while(l){
            l->val=v[i++];
            l=l->next;
        }
        return head;
        
    }
};