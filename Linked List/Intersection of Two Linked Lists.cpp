// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node* next;
};

void printList(struct node *node)
{
    while(node!=NULL){
        cout<<node->data<<' ';
        node = node->next;
    }
    printf("\n");
}

void push(struct node** head_ref, int new_data)
{
    struct node* new_node =	(struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

struct node* findIntersection(struct node* head1, struct node* head2);

int main()
{
    long test;
    cin>>test;
    while(test--)
    {
        struct node* a = NULL;
        struct node* b = NULL;
        int n, m, tmp;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>tmp;
            push(&a, tmp);
        }
        cin>>m;
        for(int i=0; i<m; i++)
        {
            cin>>tmp;
            push(&b, tmp);
        }
        printList(findIntersection(a, b));
    }
    return 0;
}
// } Driver Code Ends
/*This is a function problem.You only need to complete the function given below*/
/*
structure of the node is as
struct node
{
	int data;
	struct node* next;
};
*/

void split(struct node *source, struct node **a, struct node **b) {
    struct node *slow = source;
    struct node *fast = source->next;
    while(fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
    }
        *a = source;
        *b = slow->next;
        slow->next = NULL;
} 
struct node *merge(struct node *a, struct node *b) {
    struct node *result = NULL;
    if(a == NULL)
        return b;
    if(b == NULL)
        return a;
    if(a->data < b->data) {
        result = a;
        result->next = merge((a->next), b);
    } 
    else {
        result = b;
        result->next = merge((b->next), a);
    }
    return result;
}
struct node* mergeSort(struct node* head) {
    // your code here
    struct node *root = head;
    struct node *a;
    struct node *b;
    
    if(head == NULL || head->next == NULL) {
        return head;
    }
    
    split(root, &a, &b);
    
    a = mergeSort(a);
    b = mergeSort(b);
    
    root = merge(a, b);
    return root;
}
struct node* findIntersection(struct node* head1, struct node* head2)
{
    head1 = mergeSort(head1);
    head2 = mergeSort(head2);
    
    struct node *dummy = new struct node();
    dummy->next = NULL;
    struct node *res = dummy;
    
    
    while(head1 && head2) {
        if(head1->data == head2->data) {
            dummy->next = head1;
            dummy = dummy->next;
            head1 = head1->next;
            head2 = head2->next;
        }
        else if(head1->data < head2->data) {
            head1 = head1->next;
        }
        else {
            head2 = head2->next;
        }
    }
    dummy->next = NULL;
    return res->next;
}
