#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

// A wrapper over leftViewUtil()
void leftView(struct Node *root);


/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d\n",&n);
     struct Node *root = NULL;
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

     leftView(root);
     cout << endl;
  }
  return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
 
void func(Node *root, int *a, int i) {
    // base case
    if(root == NULL) {
        return;
    }
    
    // If this is the first node of its level 
    if(a[i] == 0) {
        a[i] = root->data;
    }
    
    // left sub tree
    if(root->left) {
        func(root->left, a, i+1);
    }
    // right sub tree
    if(root->right) {
        func(root->right, a, i+1); 
    }
}
// A wrapper over leftViewUtil()
void leftView(Node *root)
{
   int a[100] = {0};
   func(root, a, 0);
   
   // print left view of tree
   for(int i = 0; i < 100 ; i++) {
       if(a[i] != 0) { 
           cout<<a[i] << " ";
       }
       else {
           break;
       }
   }
}
