// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}

struct Node * mergeResult(struct Node *node1,struct Node *node2);

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }

        struct Node* result = mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}
// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
int data;
Node* next;
};

*/

struct Node * reverse(Node *head) {
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


struct Node * mergeResult(Node *node1,Node *node2)
{
    Node *head1 = node1;
    Node *head2 = node2;
    Node *res = newNode(0);
    Node *curr = res;
    while(head1 && head2) {
        if(head1->data < head2->data) {
            curr->next = head1;
            head1 = head1->next;
        }
        else {
            curr->next = head2;
            head2 = head2->next;
        }
        curr = curr->next;
    }
    if(!head1) {
        while(head2) {
            curr->next = head2;
            head2 = head2->next;
            curr = curr->next;
        }
    }
    if(!head2) {
        while(head1) {
            curr->next = head1;
            head1 = head1->next;
            curr = curr->next;
        }
    }
    return reverse(res->next);
}
