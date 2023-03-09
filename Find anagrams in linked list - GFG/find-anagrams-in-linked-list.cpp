//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  public:
    vector<Node*> findAnagrams(struct Node* head, string s) {
        vector<int> m1(26,0),m2(26,0);
        vector<Node*> ans;
        for(auto i: s)m1[i-'a']++;
        
        Node* left=head,*right=head;
        Node* prev=head;
        int n=s.size();
        while(n-- && right){
            m2[right->data-'a']++;
            prev=right;
            right=right->next;
        }
        if(n>0)return ans;
        
        while(right){
            if(m2==m1){
                ans.push_back(left);
                // cout<<prev->data<<endl;
                prev->next=NULL;
                left=right;
                m2.assign(26,0);
                n=s.size();
                while(n-- && right){
                    m2[right->data-'a']++;
                    prev=right;
                    right=right->next;
                }
                if(n>0)return ans;
                continue;
            }
            m2[left->data-'a']--;
            m2[right->data-'a']++;
            left=left->next;
            prev=right;
            right=right->next;
        }
        
        
        if(m2==m1){
                ans.push_back(left);
            }
        
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}

// } Driver Code Ends