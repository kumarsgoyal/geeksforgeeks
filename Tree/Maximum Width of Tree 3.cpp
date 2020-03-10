// using preorder traversal or we can use inorder, postorder also

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

int getMaxWidth(Node* root);

int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        string inp;
        getline(cin, inp);
        Node* root = buildTree(inp);
        
        cout << getMaxWidth(root) <<endl;
    }
    return 0;
}


// } Driver Code Ends
/*  Structure of a Binary Tree 

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

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node *root) {
    if(root == NULL) {
        return 0;
    }
    
    return max(height(root->left), height(root->right)) + 1;
}

void preOrder(Node *root, int *arr, int level) {
    if(root == NULL) {
        return;
    }
    arr[level] += 1;
    
    preOrder(root->left, arr, level + 1);
    preOrder(root->right, arr, level + 1);
    
}

/* Function to get the maximum width of a binary tree*/
int getMaxWidth(Node* root)
{
    if(root == NULL) {
        return 0;
    }
    
    int high = height(root);
    int *arr_width = new int [high];
    for(int i = 0; i < high; i++) {
        arr_width[i] = 0;
    }
    
    int max_result = 0;
    preOrder(root, arr_width, 0);
    
    for(int i = 0; i < high; i++) {
        max_result = max(max_result, arr_width[i]);
    }
    
        
    return max_result;
}

