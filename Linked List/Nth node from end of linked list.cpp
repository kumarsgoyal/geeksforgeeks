int len(Node *head)
{
    int count = 0;
    while(head)
    {
        count++;
        head = head->next;
    }
    return count;
}

int getNthFromLast(Node *head, int n)
{
       // Your code here
    Node *main = head;
    Node *last = head;

    int leng = len(head);
    if(n > leng)
    {
        return -1;
    }

    while(--n)
    {
        last = last->next;
    }
       
    while(last->next)
    {
        last = last->next;
        main = main->next;
    }
    return main->data;
}
