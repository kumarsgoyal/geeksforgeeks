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
    //Your code here
    if(head != NULL && head->next != NULL) {
    bool res;
    Node *slow = head;
    Node *fast = head;
    
    Node *prev = NULL;
    Node *second = NULL;
    Node *mid = NULL;
    
    while(fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    if(fast != NULL) {
        mid = slow;
        slow = slow->next;
    }
    
    second = slow;
    prev->next = NULL;
    
    reverse(&second);
    
    res =  cmp(head, second);
    
    reverse(&second);
    
    if(mid != NULL) {
        prev->next = mid;
        mid->next = second;
    }
    
    
    return res;
    }
    else {
        return 1;
    }
}
