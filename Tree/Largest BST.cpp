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

struct subtreeinfo {
    int flag, size, min, max;
    subtreeinfo(int a, int b, int c, int d) {
        flag = a;
        size = b;
        min = c;
        max = d;
    }
};

subtreeinfo* isBST(Node *root) {
    if(root == NULL) {
        return new subtreeinfo(1, 0, INT_MAX, INT_MIN);
    }
    
    subtreeinfo *left = isBST(root->left);
    subtreeinfo *right = isBST(root->right);
    
    subtreeinfo *rootcurr;
    
    if((left->flag) && (right->flag) && 
        (root->data > left->max && root->data < right->min)) {
        
        rootcurr = new subtreeinfo(1, (left->size + right->size + 1), 
            min(root->data, min(left->min, right->min)), 
            max(root->data, max(left->max, right->max)));
    }
    else {
        rootcurr = new subtreeinfo(0, max(left->size, right->size),
        0, 0);
    }
    delete(left);
    delete(right);
    
    return rootcurr;
}
int largestBst(Node *root)
{   
    subtreeinfo *rootNode = isBST(root);
    
    return rootNode->size;
}
