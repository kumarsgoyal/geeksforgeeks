int GetNth(struct node* head, int index){
  // Code here
  
    struct node* temp=head;
    int count=0;
    while(index != count)
    {
        count++;
        temp=temp->next;
    }
    return temp->data;
}
