// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


// Rearranges given linked list such that all even
// positioned Nodes are before odd positioned.
// Returns new head of linked List.
Node *rearrangeEvenOdd(Node *head);

/* Driver program to test above function*/
int main()
{
    int T,i,n,l;

    cin>>T;

    while(T--)
    {
        struct Node *head = NULL;
        struct Node *temp = head;
        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>l;

            if (head == NULL)
            {   
                head = temp = new Node(l); 
                
            }
            else
            {  temp->next = new Node(l);
               temp = temp->next;
            }
        }

        head = rearrangeEvenOdd(head);
        while(head != NULL)
        {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
    return 0;
}
// } Driver Code Ends
/* Node structure

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

// Should rearrange given linked list such that all even
// positioned Nodes are before odd positioned.
// Returns new head of linked List.
Node *rearrangeEvenOdd(Node *head)
{
    Node *odd = new Node(0); // dummy node for odd list
    Node *even = new Node(0); //dummy node for even list
    Node *evenptr = even;
    Node *oddptr = odd;
   
    Node *curr = head;
    int pos = 1;
    while(curr) {
        if(pos % 2) { // odd
            oddptr->next = curr;
            oddptr = oddptr->next;
        }
        else { // even
            evenptr->next = curr;
            evenptr = evenptr->next;
        }
        pos++;
        curr = curr->next;
    }
    
    evenptr->next = NULL;
    oddptr->next = even->next;
    return odd->next;
    
}
