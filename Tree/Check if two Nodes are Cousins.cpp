// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
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

bool isCousins(Node*root , int x , int y);

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        int x , y;
        scanf("%d ",&x);
		scanf("%d ",&y);
        if(x==y)
        {
            cout<<"0\n";
            continue;
        }
        cout <<isCousins(root,x,y)<< endl;
    }
    return 1;
}// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node{
  ll data;
  Node *left,*right;
};
*/

int isSibling(Node *root, int x, int y) {
    if(root == NULL) {
        return 0;
    }
    
    queue<Node*> que;
    que.push(root);
    Node *first = NULL;
    Node *second = NULL;
    
    while(!que.empty()) {
        int size = que.size();
        
        while(size--) {
            Node *temp = que.front();
            que.pop();
            
            if(temp->left && temp->left->data == x) {
                first = temp;
            }
            else if(temp->left && temp->left->data == y) {
                second = temp;
            }
            else if(temp->right && temp->right->data == x) {
                first = temp;
            }
            else if(temp->right && temp->right->data == y) {
                second = temp;
            }
            
            if(temp->left) {
                que.push(temp->left);
            }
            if(temp->right) {
                que.push(temp->right);
            }
        }
        
        
        // both are at same level
        if(first && second) {
            // parent of both are not same
            if(first != second) {
                return 1;
            }
            // parent of both are same
            else {
                return 0;
            }
        }
        else if(first || second) {
            // both are not at same level
            return 0;
        }
    }
    
    // if none of them is found
    return 0;
 
}

bool isCousins(Node *root, int x, int y)
{
   return isSibling(root, x, y);
}
