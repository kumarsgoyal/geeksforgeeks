// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

int maxDiff(Node* , int );

void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        *tree = new Node(val);
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}


int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

        int s;
        cin>>s;

     cout<<maxDiff(root,s);
     cout<<endl;
    }
}
// } Driver Code Ends
/*The Node structure is
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/

void minDiffUtil(Node *root, int &result, int k) {
    if(root == NULL) {
        return;
    }
    
    result = min(result, abs(root->data - k));
    
    minDiffUtil(root->left, result, k);
    minDiffUtil(root->right, result, k);

}

/*You are required to complete below method */
int maxDiff(Node *root, int k)
{
    if(root == NULL) {
        return 0;
    }
    
    
    int result = INT_MAX;
    
    minDiffUtil(root, result, k);
    return result;
}
