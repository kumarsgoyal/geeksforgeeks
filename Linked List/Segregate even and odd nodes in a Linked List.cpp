#include<bits/stdc++.h>

using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node* insert(Node *head,int data)
{
    Node *temp=new Node();
    temp->data=data;
    temp->next = head;
    return temp;
}

Node* reverse(Node *head) {
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;
    
    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}

void print(Node *head)
{
    head = reverse(head);
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,x;
	    cin>>n;
	    Node *odd=NULL,*even=NULL;
	    for(int i=0;i<n;i++)
	    {
	        cin>>x;
	        if(x%2==0)
	            even=insert(even,x);
	        else
	            odd=insert(odd,x);
	    }
	    if(!even)
	       print(odd);
	    else{
    	    Node *temp=odd;
    	    while(temp->next)
    	        temp=temp->next;
    	    temp->next=even;
    	    print(odd);
	        
	    }
	}
	return 0;
}
