// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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

void topView(struct Node *root);


int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,i,k;
        cin>>n;
        i=n;

        Node* root=NULL;
        queue <Node*> q;
        while(i>0)
        {
            int a,b;
            char c;
            cin>> a >> b >> c;
            if(!root){
                root = new Node(a);
                q.push(root);
            }
            Node* pick = q.front();
            q.pop();

            if(c == 'L'){
                pick->left = new Node(b);
                q.push( pick->left );
            }
            cin>> a >> b >> c;
            if(c == 'R'){
                pick->right = new Node(b);
                q.push( pick->right );
            }
            i-=2;
        }
//        inorder(root);
//        cout<<endl;
        topView(root);
        cout << endl;
    }
    return 0;
}




// } Driver Code Ends

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
void func(struct Node *root, map<int, pair<int, int>> &mp, int h, int level) {
    
    if(root == NULL) {
        return;
    } 
    
    if((mp.find(h) != mp.end())) {
        if(mp.find(h)->second.first > level)
        {
           mp.find(h)->second.second = root->data; 
           mp.find(h)->second.first = level; 
        }
    }
    else {
        mp.insert({h, make_pair(level, root->data)});
    }
    func(root->left, mp, h-1, level+1);
    func(root->right, mp, h+1, level+1);
}

void topView(struct Node *root)
{
    map<int, pair<int, int>> mp;
    func(root, mp, 0, 1);
    
    for(auto i = mp.begin(); i != mp.end(); i++) {
        cout<<i->second.second<<" ";
    }
    
}
