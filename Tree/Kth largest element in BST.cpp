// { Driver Code Starts
#include<iostream>
using namespace std;

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

void kthLargest(Node *root, int k);
Node* insert(Node* node, int key)
{
    if (node == NULL) return new Node(key);
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}
int main()
{
    int t;
	cin>>t;
	while(t--)
	{
		Node *root = NULL;
		int n;
		cin>>n;
		int a;
		cin>>a;
		root = insert(root, a);
		for(int i=0;i<n-1;i++)
		{
			cin>>a;
			insert(root,a);
		}
		int k;
		cin>>k;
		kthLargest(root, k);
	}
    return 0;
}
// } Driver Code Ends
/*The Node structure is defined as
struct Node
{
    int key;
    Node *left, *right;
}; */


void findKthLargest(Node *root, int k, int &count) {
    if(root == NULL || count >= k) {
        return;
    }
    
    findKthLargest(root->right, k, count);
    
    count++;
    
    if(count == k) {
        cout<<root->key<<endl;
        return;
    }
    
    findKthLargest(root->left, k, count);
}

/*Complete the function below*/
void kthLargest(Node *root, int k)
{
    int count = 0;
    findKthLargest(root, k, count);
}
