void swap(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

Node* pairWiseSwap(struct Node* head)
{
   // The task is to complete this method
   struct Node *curr = head;
   while(curr && curr->next) {
       swap(&curr->data, &curr->next->data);
       curr = curr->next->next;
   }
   return head;
   
}
