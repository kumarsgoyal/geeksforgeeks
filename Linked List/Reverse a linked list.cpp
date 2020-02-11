Node* reverseList(Node *head)
{
  // Your code here
  Node *curr = head;
  Node *next = NULL;
  Node *prev = NULL;
  
  while(curr != NULL) {
      next = curr->next;
      curr->next = prev;
      
      prev = curr;
      curr = next;
  }
  return prev;
}
