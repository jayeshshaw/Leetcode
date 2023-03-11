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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<int> nodes;
    TreeNode* maketree(int a, int b){
        if(a>b)return NULL;
        int mid=a+(b-a)/2;
        TreeNode* n=new TreeNode(nodes[mid]);
        n->left=maketree(a,mid-1);
        n->right=maketree(mid+1,b);
        return n;
    }
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* temp=head;
        while(temp){
            nodes.push_back(temp->val);
            temp=temp->next;
        }
        return maketree(0,nodes.size()-1);
    }
};