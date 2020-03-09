#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

void printBST(Node *root) {
    if(root == NULL) {
        return;
    }
    
    cout<<root->data<<" ";
    printBST(root->left);
    printBST(root->right);
}

Node* createBST(int *arr, int start, int end) {
    if(start > end) {
        return NULL;
    }
    
    int mid = (start + end) / 2;
    Node *temp = new Node(arr[mid]);
    
    temp->left = createBST(arr, start, mid-1);
    
    temp->right = createBST(arr, mid+1, end);
    
    return temp;
}

int main() {
	int t = 0;
	cin>>t;
	
	while(t--) {
	    int size = 0;
	    cin>>size;
	    
	    int *Arr = new int[size];
	    
	    for(int i = 0; i < size; i++) {
	        cin>>Arr[i];
	    }
	    
	    Node *root = createBST(Arr, 0 ,size-1);
	    printBST(root);
	    cout<<endl;
	    
	}
	return 0;
}
