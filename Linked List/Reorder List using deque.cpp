// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include<bits/stdc++.h>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void reorderList(struct Node* head);

/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }

        reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}
// } Driver Code Ends
/* Following is the Linked list node structure */

/*
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

void reorderList(Node* head) {
    
    if(head == NULL) {
        return;
    }
    
    if(head != NULL && head->next == NULL) {
        return;
    }
    
    deque<Node *> dq;
    
    Node *curr = head;
    
    while(curr) {
        dq.push_back(curr);
        curr = curr->next;
    }
    
    Node *prev = NULL;
    while(dq.size() > 1) {
        if(prev == NULL) {
            prev = dq.front();
            dq.pop_front();
        }
        else {
            prev->next = dq.front();
            prev = dq.front();
            dq.pop_front();
        }
        
        prev->next = dq.back();
        prev = dq.back();
        dq.pop_back();
    }
    
    if(!dq.empty()) {
        prev->next = dq.front();
        prev = dq.front();
        dq.pop_front();
    }
    
    prev->next = NULL;
}
