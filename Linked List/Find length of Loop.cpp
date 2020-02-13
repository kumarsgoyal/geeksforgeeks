int getresult(struct Node *loop)
{
    int res = 1;
    struct Node *temp = loop;
    while(temp->next != loop)
    {
        temp = temp->next;
        res++;
    }
    return res;
}
int countNodesinLoop(struct Node *head)
{
     // Code here
     struct Node *slow = head;
     struct Node *fast = head;
     
     while(slow && fast && fast->next)
     {
         slow = slow->next;
         fast = fast->next->next;
         if(slow == fast)
            return getresult(slow);
     }
     return 0;
}
