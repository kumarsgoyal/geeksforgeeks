// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
 
/* a Node of the doubly linked list */
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;    
};
 struct Node* newNode(struct Node* head,int data){
	 struct Node *p,*temp= (struct Node*)malloc(sizeof(struct Node));
	 temp->data=data;
	 temp->next=NULL;
	 temp->prev=NULL;
	 if(head ==NULL)
	 return temp;
	 p=head;
	 while(p->next!=NULL){
	 p=p->next;}
	 p->next=temp;
	 temp->prev=p;
	 return head; 
	 }
void reverse(struct Node **head_ref);
void printList(struct Node *Node)
{
  while(Node!=NULL)
  {
   printf("%d ", Node->data);
   Node = Node->next;
  }
  printf("\n");
} 
 int main()
{
  int t,x,n,i;
  scanf("%d",&t);
  while(t--)
  {
  /* Start with the empty list */
  struct Node *temp,*head = NULL;
  scanf("%d",&n);
  for(i=0;i<n;i++){
  scanf("%d",&x);
  head=newNode(head, x);
  }
  reverse(&head);  
  printList(head);
  while(head->next!=NULL)
  {
	  temp=head;
	  head=head->next;
	  free(temp);
	  }       
	}
	return 0;
}
// } Driver Code Ends
/* a Node of the doubly linked list */
/*struct Node
{
  int data;
  Node *next;
  Node *prev;    
};*/
void reverse(Node **head_ref)
{
    Node *curr = *head_ref;
    Node *new_head = NULL;
    while(curr) {
        Node *temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        
        new_head = curr;
        curr = curr->prev;
    }
    
    *head_ref = new_head;
}
