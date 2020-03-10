// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
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

void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);    
}

int largestBst(Node *root);

/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);

        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];

        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }

    cout<<largestBst(root)<< endl;
  }
  return 0;
}


// } Driver Code Ends
/* Tree node structure  used in the program
 struct Node
 {
     int data;
     struct Node* left, *right;
};*/

/*You are required to complete this method */


int size(Node *root) {
    if(root == NULL) 
        return 0;
        
    return (size(root->left) + size(root->right) + 1);
}


int isBST(Node *root, int min, int max) {
    if(root == NULL) {
        return 1;
    }
    
    if(root->data < min || root->data > max) {
        return 0;
    } 
    
    return isBST(root->left, min, root->data - 1) &&
        isBST(root->right, root->data + 1, max);
}
int largestBst(Node *root)
{   
    if(root == NULL) {
        return 0;
    }
    
    if(isBST(root, 1, 1000)) {
        return size(root);
    }
    
    return max(largestBst(root->left), largestBst(root->right));
}
