void intersection(Node **head1, Node **head2,Node **head3)
{
    // Your Code Here
    Node *a = *head1;
    Node *b = *head2;
    Node *dummy = (Node *)malloc(sizeof(Node));
    Node *res = dummy;
    res->next = NULL;
    
    
    while(a && b) {
        if(a->val == b->val) {
            res->next = a;
            a = a->next;
            b = b->next;
            res = res->next;
        }
        else if(a->val < b->val) {
            a = a->next;
        }
        else {
            b = b->next;
        }
    }
    res->next = NULL;
    *head3 = dummy->next;
}
