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


bool isPalindrome(Node *head)
{
    // Linked list is having only one node
    if(head != NULL && head->next == NULL) {
        return 1;
    }
    
    else {
        stack<int> stk;
        Node *curr = head;
        
        while(curr) {
            stk.push(curr->data);
            curr = curr->next;
        }
        
        
        curr = head;
        while(curr) {
            int top = stk.top();
            stk.pop();
            
            if(top != curr->data) {
                return 0;
            }
            
            curr = curr->next;
        }
        
        
        return 1;
        
        
    }
}
