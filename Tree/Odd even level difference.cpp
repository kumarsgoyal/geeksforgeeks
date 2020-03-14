// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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


int getLevelDiff(Node *root);

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



int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        cout<<getLevelDiff(root);
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends
/* The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

/*You are required to complete this function*/

void getLevelSum(Node *root, int &even, int &odd) {
    queue<Node*> que;
    int sum = 0; // sum of each level
    int level = 1; // root level is 1
    que.push(root);
    
    
    while(que.empty() == false) {
        sum = 0;
        int size = que.size();
        
        while(size--) {
            Node *temp = que.front();
            que.pop();
            
            sum += temp->data;
            
            if(temp->left) {
                que.push(temp->left);
            }
            if(temp->right) {
                que.push(temp->right);
            }
        }
        
        if(level%2) { //level is odd
            odd += sum;
        }
        else {
            even += sum;
        }
        
        level++;
    }
}

int getLevelDiff(Node *root)
{
    int evenSum = 0;
    int oddSum = 0;
    
    getLevelSum(root, evenSum, oddSum);
    
    return oddSum - evenSum;
    
}

