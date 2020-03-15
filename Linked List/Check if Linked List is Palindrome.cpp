// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
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

void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}


bool isPalindrome(Node *head);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l;
    cin>>T;
    while(T--){
    struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
   	cout<<isPalindrome(head)<<endl;
    }
    return 0;
}

// } Driver Code Ends
/*This is a function problem.You only need to complete the function given below*/

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
/*You are required to complete this method */

void reverse(Node **head) {
    Node *curr = *head;
    Node *prev = NULL;
    Node *next = NULL;
    
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    *head = prev;
}

bool cmp(Node *head1, Node *head2) {
    Node *node1 = head1;
    Node *node2 = head2;
    
    while(node1 && node2) {
        if(node1->data == node2->data) {
            node1 = node1->next;
            node2 = node2->next;
        }
        else {
            return false;
        }
    }
    if(node1 == NULL && node2 == NULL) {
        return true;
    }
    return false;
    
}

bool isPalindrome(Node *head)
{
    // Linked list is having only one node
    if(head != NULL && head->next == NULL) {
        return 1;
    }
    
    else {
        
        bool res;
        
        // find middle element
        Node *slow = head; // slow pointer
        Node *fast = head; // fast pointer
        Node *prev = NULL; 
        
        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        
        Node *mid = NULL;
        // in case of odd element in list fast is not NULL
        // in case of even element fast is NULL
        // and we store mid element so that odd list is divided equally
        if(fast != NULL) {
            mid = slow;
            slow = slow->next;
        }
        
        // store head to second half
        Node *second = NULL;
        second = slow;
        
        // to terminate first half linked list
        prev->next = NULL;
        
        reverse(&second);
        
        res =  cmp(head, second);
        
        reverse(&second);
        
        // join two list again
        if(mid != NULL) {
            prev->next = mid;
            mid->next = second;
        }
        else {
            prev->next = second;
        }
        return res;
    }
}
