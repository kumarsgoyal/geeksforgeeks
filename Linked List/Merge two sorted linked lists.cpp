// { Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};

Node* sortedMerge(struct Node* a, struct Node* b);

void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int T,i,n1,n2,l,k;

    cin>>T;

    while(T--)
    {
        struct Node *head1 = NULL,  *tail1 = NULL;
        struct Node *head2 = NULL,  *tail2 = NULL;

        cin>>n1>>n2;
        for(i=1; i<=n1; i++)
        {
            cin>>l;
            append(&head1, &tail1, l);
        }
        for(i=1; i<=n2; i++)
        {
            cin>>l;
            append(&head2, &tail2, l);
        }
        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}



// } Driver Code Ends
/*This is a function problem.You only need to complete the function given below*/
 
/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
// Function to merge the two sorted linked lists
// head1, head2: head of the two sorted linked lists


Node *reverse(Node *head) {
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

Node* sortedMerge(Node* head1,   Node* head2)
{
    Node *dummy = (Node *)malloc(sizeof(Node));
    Node *tail = dummy;
    Node *temp;
    
    tail->next = NULL;
    
    // base case if linklist with head1 node is NULL
    if(head1 == NULL) {
        tail->next = head2;
        return tail->next;
    }
    // base case if linklist with head2 node is NULL
    else if(head2 == NULL) {
        tail->next = head1;
        return tail->next;
    }
    else {
        // travese linklist and start merging
        // always push element if front of linklist at last reverse
        while(head1 && head2) {
            if(head1->data <= head2->data) {
                temp = head1;
                head1 = head1->next;
                temp->next = tail->next;
                tail->next = temp;
            }
            else {
                temp = head2;
                head2 = head2->next;
                temp->next = tail->next;
                tail->next = temp;
            }
        }
        
        // linklist with head2 node is terminated
        if(head1) {
            while(head1) {
                temp = head1; 
                head1 = head1->next; 
                temp->next = tail->next; 
                tail->next = temp;
            }
        }
        
        // linklist with head1 node is terminated
        if(head2) {
            while(head2) {
                temp = head2;
                head2 = head2->next;
                temp->next = tail->next;
                tail->next = temp;
            }
        }
        
    }
    return reverse(tail->next);
    
    
    /*
      Another approach first reverse both linkedlist and start merging according 
      to largest element first (because we were adding adding element at head of dummy linkedlist)
      at last we get our result.  
    */
}
