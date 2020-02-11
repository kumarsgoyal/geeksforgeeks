int length(Node *head) {
    int count = 0;
    while(head) {
        count++;
        head = head->next;
    }
    return count;
}
Node* rotate(Node* head, int k) {
    int len = length(head);
    if(len == k) {
        return head;
    }
    else {
        Node *curr = head;
        Node *prev = NULL;
        Node *res = NULL;
        while(curr && k) {
            prev = curr;
            curr = curr->next;
            k--;
        }
        prev->next = NULL;
        res = curr;
        while(curr) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = head;
        return res;
    }
    
}
