// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
void dfs(int v, vector<int> adj[], int arr[], int &flag) {
    arr[v] = 0;
    for(auto i = adj[v].begin(); i != adj[v].end(); i++) {
        if(arr[*i] == 0) {
            flag = 1;
            return;
        }
        if(arr[*i] == -1) {
            dfs(*i, adj, arr, flag);
        }
    }
    
    arr[v] = 1;
}

bool isCyclic(int V, vector<int> adj[])
{
    
    int *Arr = new int[V];
    int res = 0; 
    
    for(int i = 0; i < V; i++) {
        Arr[i] = -1;
    }
    
    for(int i = 0; i < V; i++) {
        if(Arr[i] == -1) {
            dfs(i, adj, Arr, res);
        }   
        if(res == 1) {
            return true;
        }
    }
    
    return false;
}

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
