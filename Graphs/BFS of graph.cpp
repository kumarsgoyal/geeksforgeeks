// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/* You have to complete this function*/

/* Function to do BFS of graph
*  adj[]: array of vectors
*  vis[]: array to keep track of visited nodes
*/
void bfs(int s, vector<int> adj[], bool vis[], int N)
{
    queue <int> que;
    que.push(s);
    vis[s] = true;
    
    while(!que.empty()) {
        int node = que.front();
        cout<<node<<" ";
        que.pop();
        for(auto i: adj[node]) {
            if(!vis[i]) {
                que.push(i);
                vis[i] = true;
                
            }
        }
    }
    return;
}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        
        int N, E;
        cin>>N>>E;
        vector<int> adj[N];
        bool vis[N] = {false};
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        
        bfs(0, adj, vis, N);

        cout<<endl;

    }
}

  // } Driver Code Ends
