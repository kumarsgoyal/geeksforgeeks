// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
/* This function is used to detect a cycle in undirected graph
*  adj[]: array of vectors to represent graph
*  V: number of vertices
*/

void dfs(vector<int> adj[], int visted[], int m, int &res, int parent) {
    visted[m] = 1;
    for(auto i = adj[m].begin(); i != adj[m].end(); i++) {
        if(visted[*i] && (*i != parent)) {
            res = 1;
            return;
        }
        if((visted[*i] == 0) && (res == 0)) {
            dfs(adj, visted, *i, res, m);
        }
    }
}

bool isCyclic(vector<int> adj[], int V)
{
    int *visted = new int[V];
    for(int i = 0; i < V; i++) {
        visted[i] = 0;
    }
    
    int res = 0;
    
    for(int i = 0; i < V; i++) {
        for(auto j = adj[i].begin(); j != adj[i].end(); j++) {
            if(i == *j) {
                return true;
            }
        }
    }
    
    for(int i = 0; i < V; i++) {
        if(visted[i] == 0) {
            dfs(adj, visted, i, res, -1);
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
