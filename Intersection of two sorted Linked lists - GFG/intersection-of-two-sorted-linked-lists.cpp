// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}
// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node* findIntersection(Node* head1, Node* head2)
{
    if(head1==NULL) return NULL;
     if(head2==NULL) return head2;
     Node* h1=head1;
     Node* h2=head2;
     Node* i=NULL;
     Node* j=NULL;
     
     while(h1!=NULL && h2!=NULL)
     {
         if(h1->data<h2->data)
         {
             h1=h1->next;
         }
         else if(h2->data<h1->data)
         {
             h2=h2->next;
         }
         else
         {
             if(i==NULL)
             {
                 i=h1;
                 j=h1;
                 
             }else
             {
                 j->next=h1;
                 j=h1;
             }
             h1=h1->next;
             h2=h2->next;
             j->next=NULL;
         }
     }
     return i;
}