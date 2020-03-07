// { Driver Code Starts
//Code by 1shubhamjoshi1
#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        *tree = new Node(val);
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}


Node* LCA(Node *root, int , int );

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

        int l,r;
        cin>>l>>r;

        cout<<LCA(root,l,r)->data<<endl;
    }
}
// } Driver Code Ends
/*This is a function problem.You only need to complete the function given below*/
/*The structure of a BST Node is as follows:
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/
/*You are required to complete
this function*/
int find(Node *root, int x, int *a) {
    int done = 1;
    int count = 0;
    while(done) {
        
        a[count++] = root->data;
        if(root->data == x) {
            done = 0;
        }
        else if(root->data < x) {
            root = root->right;
        }
        else if(root->data > x) {
            root = root->left;
        }
    }
    return count;
}

Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   int a[100] = {0};
   int b[100] = {0};
   int count1 = find(root, n1, a);
   int count2 = find(root, n2, b);
   int result = 0, i = 0, j = 0;
   while(i < count1 && j < count2) {
       if(a[i] == b[j]) {
           result = a[i];
       }
       else {
           break;
       }
       i++;
       j++;
   }
   Node *res = new Node(result);
   return res;
}
