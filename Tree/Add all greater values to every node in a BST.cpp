// { Driver Code Starts
//Code by 1shubhamjoshi1
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
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
void inorderrrrr(Node *root)
{
    if(root!=NULL)
    {
    inorderrrrr(root->left);
    cout<<root->data<< " ";
    inorderrrrr(root->right);
    }
}
void modify(Node **root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;
        root = NULL;
        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);
        }
        modify(&root);
        inorderrrrr(root);
        cout<<endl;
    }
}// } Driver Code Ends
/* BST Node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

void modifyBST(Node *root, int &sum) {
    if(root == NULL) {
        return ;
    }
    
    modifyBST(root->left, sum);
    
    // get copy of data of original tree
    // copy sum to that value
    // modify sum
    int data = root->data;
    root->data = sum;
    sum -= data;
    
    modifyBST(root->right, sum);
    
}

void getSum(Node *root, int &sum) {
    if(root == NULL) {
        return;
    }
    
    getSum(root->left, sum);
    
    sum += root->data;
    
    getSum(root->right, sum);
}

/*  modifies the root of the bst */
void modify(Node **root)
{
    int sum = 0;
    
    // get sum of whole tree
    getSum(*root, sum);
    modifyBST(*root, sum);
    return;
}
