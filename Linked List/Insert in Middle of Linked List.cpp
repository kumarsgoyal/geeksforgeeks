// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
// function to display the linked list
void display(Node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout<<endl;
}

void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

Node* insertInMiddle(Node* head, int x);

int main()
{
    int n, k, T, l, x;
    cin>>T;
    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for (int i=0; i<n; i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
        cin>>x;
        head = insertInMiddle(head, x);
        display(head);
    }
    return 0;
}
// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

// function should insert node at the middle
// of the linked list
Node* insertInMiddle(Node* head, int x)
{
	if(head == NULL) {
	    return new Node(x);
	}
	
	if(head != NULL && head->next == NULL) {
	    head->next = new Node(x);
	    return head;
	}
	
	Node *slow = head;
	Node *fast = head;
	Node *prev = NULL;
	while(fast && fast->next) {
	    fast = fast->next->next;
	    prev = slow;
	    slow = slow->next;
	}
	
	if(fast) {
	    Node *next = slow->next;
	    slow->next = new Node(x);
	    slow->next->next = next;
	    
	}
	else {
	    prev->next = new Node(x);
	    prev->next->next = slow;
	}
	
	return head;
}
