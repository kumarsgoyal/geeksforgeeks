// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
/* This function is used to detect a cycle in undirected graph
*  adj[]: array of vectors to represent graph
*  V: number of vertices
*/

void bfs(vector<int> adj[], int V, int arr[], int &res) {
    queue<int> que;
    que.push(V);
    arr[V] = 0;
    
    while(!que.empty()) {
        int temp = que.front(); 
        que.pop(); 
        arr[temp] = 1; 
        
        for(auto j = adj[temp].begin(); j != adj[temp].end(); j++) {
            if(arr[*j] == 0) {
                res = 1;
                return;
            }
            if(arr[*j] == -1) {
                que.push(*j);
                arr[*j] = 0;
            }
        }
    }
    return;
}

bool isCyclic(vector<int> adj[], int V)
{
    int *arr = new int[V];
    for(int i = 0; i < V; i++) {
        arr[i] = -1;
    }
    
    for(int i = 0; i < V; i++) {
        for(auto j = adj[i].begin(); j != adj[i].end(); j++) {
            if(*j == i) {
                return true;
            }
        }
    }
    
    int res = 0;
    for(int i = 0; i < V; i++) {
        if(arr[i] = -1) {
            bfs(adj, i, arr, res);   
        }
        if(res == 1) {
            return true;
        }
    }
    
    return false;
}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
  // } Driver Code Ends
