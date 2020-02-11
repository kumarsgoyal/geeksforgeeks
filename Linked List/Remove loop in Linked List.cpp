void removeTheLoop(Node *head)
{
     //Your code here
     if(head == NULL) {
         return;
     }
     Node *slow = head;
     Node *fast = head;
     
     
     
     while(fast && fast->next) {
         fast = fast->next->next;
         slow = slow->next;
         
         if(slow == fast) {
             slow = head;
             while(slow->next != fast->next) {
                 slow = slow->next;
                 fast = fast->next;
             }
             fast->next = NULL; 
             break;
         }
         
     }
     
}
