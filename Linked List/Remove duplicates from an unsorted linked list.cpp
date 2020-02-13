Node * removeDuplicates( Node *head) 
{
 // your code goes here
    unordered_set<int> seen; 
    
    Node *curr = head; 
    Node *temp = NULL; 
    
    seen.insert(curr->data); 
    while (curr->next != NULL) 
    { 
        // If current value is seen before 
        if (seen.find(curr->next->data) != seen.end()) 
        { 
            temp = curr->next;
            curr->next = curr->next->next; 
            delete (temp); 
        } 
        else
        { 
           seen.insert(curr->next->data); 
           curr = curr->next; 
        } 
    } 
    return head;
}
