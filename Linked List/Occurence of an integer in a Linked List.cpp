int count(struct node* head, int search_for)
{
    //add your code here
    int c = 0;
    while(head)
    {
        if(head->data == search_for)
            c++;
        head = head->next;
    }
    return c;
}
