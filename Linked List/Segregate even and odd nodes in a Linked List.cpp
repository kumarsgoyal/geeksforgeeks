#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node* insert(Node *head,int data)
{
    Node *temp=new Node();
    temp->data=data;
    temp->next = head;
    return temp;
}

Node* reverse(Node *head) {
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;
    
    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}

void getprint(Node *head) {
    
    Node *even = NULL;
    even = insert(even, -1);
    Node *eptr = even;
    Node *odd = NULL;
    odd = insert(odd, -1);
    Node *optr = odd;
    
    while(head) {
        if(head->data % 2) {
            optr->next = head; 
            optr = optr->next;
        }
        else {
            eptr->next = head;
            eptr = eptr->next;
        }
        head = head->next;
    }
    
    optr->next = NULL;
    eptr->next = NULL;
    
    eptr = even->next;
    optr = odd->next;
    while(eptr) {
        cout<<eptr->data<<" ";
        eptr = eptr->next;
    }
    while(optr) {
        cout<<optr->data<<" ";
        optr = optr->next;
    }
    cout<<"\n";
    
}

void print(Node *head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}


int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n, x;
	    cin >> n;
	    Node *head = NULL;
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>x;
	        head = insert(head, x);
	    }
	    
	    head = reverse(head);
	    getprint(head);
	}
	return 0;
}
