// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
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
void printSibling(Node *root);

int main()
{
// 	freopen("input.txt","r",stdin);
// 	freopen("output.txt","w",stdout);
	
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
// 		string ch;
// 		getline(cin,ch);
		Node* root = buildTree(s);
		
        printSibling(root);
   		cout<<endl;
// 		cout<<"~\n";
  }
  return 0;
}// } Driver Code Ends
//User function Template for C++

/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

/* Prints the nodes having no siblings.  */

void getSibling(Node *node, set<int> &myset) {
    if(node == NULL) {
       return;
   }
   if(node->left && node->right) {
       getSibling(node->left, myset);
       getSibling(node->right, myset);
   }
   else if(node->left) {
       myset.insert(node->left->data);
       getSibling(node->left, myset);
   }
   else if(node->right) {
       myset.insert(node->right->data);
       getSibling(node->right, myset);
   }
}

void printSibling(Node* node)
{
   set<int> myset;
   getSibling(node, myset);
   
   if(myset.empty()) {
       cout<<-1;
   }
   else {
       for(auto i = myset.begin(); i != myset.end(); i++) {
           cout<<*i<<" ";
       }
   }
   
}
