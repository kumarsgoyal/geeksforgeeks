int len(Node *root) {
    int count = 0;
    while(root) {
        count++;
        root = root->next;
    }
    return count;
}

int func(Node *head1, Node *head2, int len1, int len2,int diff) {
    for(int i = 0; i < diff; i++) {
        head1 = head1->next;
    }
    while(head1 && head2) {
        if(head1->data == head2->data) {
            return head1->data;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return -1;
}

int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int len1 = len(head1);
    int len2 = len(head2);
    
    int diff = abs(len1 - len2);
    
    if(len1 > len2) {
        return func(head1, head2, len1, len2, diff);
    }
    else {
        return func(head2, head1, len2, len1, diff);
    }
    
}
