/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node *ptr, *temp, *temp2;
        ptr = head;
        while(ptr && ptr->child == NULL)
            ptr = ptr->next;
        if(ptr==NULL) return head;
        // while(ptr)
        else
        {   
            // Node * help=head;
            // while(help)cout<<help->val<<" ",help=help->next;
            // cout<<endl;
            temp = ptr->next;
            if(temp)
            {
                temp2 = flatten(ptr->child); //expecting to return head of flattened list
                ptr->next = temp2;
                ptr->child = NULL;
                
                Node *temp3 = temp2;
                while(temp3->next) temp3 = temp3->next;
                temp3->next = temp;
                temp->prev = temp3;
                
                ptr->next = temp2;
                temp2->prev = ptr;
                
                return head;
                
                // ptr=ptr->next;
            }
            else
            {
//                 ptr->next = ptr->child;
//                 ptr->child=NULL;
//                 temp=ptr;
//                 ptr=ptr->next;
//                 if(ptr)
//                 ptr->prev=temp;
                
                temp2 = flatten(ptr->child);
                ptr->next = temp2;
                temp2->prev=ptr;
                ptr->child = NULL;
                
                return head;
                // =ptr->next;
                // temp=ptr->next;
                // temp->prev=ptr;
                
                
            }
        }
    }
};