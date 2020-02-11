int getMiddle(Node *head)
{
   // Your code here
   Node *slow = head;
   Node *fast = head;
  
    while(fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    if(fast->next)
    {
        slow = slow->next;
    }
    return slow->data;
}
