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

void topView(struct Node *root);

/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  cin >> t;

  while (t--)
  {
     map<int, Node*> m;
     int n;
     cin >> n;
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

     topView(root);
     cout << endl;
  }
  return 0;
}

/*This is a function problem.You only need to complete the function given below*/
//Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// function should print the topView of the binary tree
void func(struct Node *root, int a[][2], int h, int level) {
    
    if(root == NULL) {
        return;
    }  
    if(a[50+h][0] == 0) {
        a[50+h][0] = level;
        a[50+h][1] = root->data;
    }
    else {
        if(a[50+h][0] > level) {
            a[50+h][0] = level;
            a[50+h][1] = root->data;
        }
    }
    func(root->left, a, h-1, level+1);
    func(root->right, a, h+1, level+1);
}

void topView(struct Node *root)
{
    int a[100][2] = {0};
    func(root, a, 0, 1);
    for(int i = 0; i < 100; i++) {
        if(a[i][0] != 0) {
            printf("%d ", a[i][1]);
        }
    }
    
}
