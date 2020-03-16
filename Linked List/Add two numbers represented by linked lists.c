// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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

struct Node* addTwoLists(struct Node* first, struct Node* second);

void push(struct Node** head_ref, int new_data) {
    struct Node* new_Node = new Node(new_data);
    new_Node->next = (*head_ref);
    (*head_ref) = new_Node;
}
void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}
void freeList(struct Node* Node) {
    struct Node* temp;
    while (Node != NULL) {
        temp = Node;
        Node = Node->next;
        free(temp);
    }
}
int main(void) {
    int t, n, m, i, x;
    cin >> t;
    while (t--) {
        struct Node* res = NULL;
        struct Node* first = NULL;
        struct Node* second = NULL;
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> x;
            push(&first, x);
        }
        cin >> m;
        for (i = 0; i < m; i++) {
            cin >> x;
            push(&second, x);
        }
        res = addTwoLists(first, second);
        printList(res);
        if (first) freeList(first);
        if (second) freeList(second);
    }
    return 0;
}
// } Driver Code Ends
/*This is a function problem.You only need to complete the function given below*/

/*
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
int len(Node *node) {
    int len1 = 0;
    while(node) {
        len1++;
        node = node->next;
    }
    return len1;
}

void push1(Node **head, int data) {
    Node* new_node =(Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

Node *reverse(Node *root) {
    Node *curr = root;
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

Node *func(Node *head1, Node *head2, int len1, int len2) {
    Node *res = NULL;
    int sum = 0;
    
    while(head1 && head2) {
        sum += head1->data;
        sum += head2->data;
        head1 = head1->next;
        head2 = head2->next;
        if(sum >= 10) {
            push1(&res, sum - 10);
            sum = 1;
        }
        else {
            push1(&res, sum);
            sum = 0;
        }
    }
    
    
    // linklist with head2 pointer to head is finished
    while(head1) {
        sum += head1->data;
        if(sum >= 10) {
            push1(&res, sum - 10);
            sum = 1;
        }
        else {
            push1(&res, sum);
            sum = 0;
        }
        head1 = head1->next;
    }
    
    
    if(sum != 0) {
        push(&res, sum);
        sum = 0;
    }
    return reverse(res);
}

// write a function returns the resultant linked list
Node* addTwoLists(Node* first, Node* second) {
    // Code here
    
    int len1 = len(first);
    int len2 = len(second);

    
    if(len1 < len2) {
        return func(second, first, len2, len1);
    }
    else {
        return func(first, second, len1, len2);
    }
    
}
