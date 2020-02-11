int detectloop(Node *head) {
    
    // your code here
    Node *slow = head;
    Node *fast = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast) {
            return 1;
        }
    }
    return 0;
    
}
