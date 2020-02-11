Node* deleteNode(Node *head,int x)
{
    int pos = 1;
    //Your code here
    Node *temp = head;
    Node *prev = NULL;
    if(x == 1)
    {
        return head->next;
    }
    while(pos != x)
    {
        ++pos;
        prev = head;
        head = head->next;
    }
    if(head != NULL)
    {
        prev->next = head->next;
    }
    return temp;
}
