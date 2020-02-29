// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int findIslands(vector<int> A[], int N, int M);
// Position this line where user code will be pasted.

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
       vector<int> A[N];
         for(int i = 0; i < N; i++) {
            vector<int> temp(M);
            A[i] = temp;
             for(int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        cout << findIslands(A, N, M) << endl;
    }
    return 0;
}// } Driver Code Ends
/*you are required to complete this method*/

/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/


int dfs(vector<int> A[], int i, int j, int N, int M) {
    if(i < 0 || i >= N || j < 0 || j >= M || A[i][j] == 0) {
        return 0;
    }
    
    A[i][j] = 0;
    dfs(A, i+1, j, N, M);
    dfs(A, i-1, j, N, M);
    dfs(A, i, j+1, N, M);
    dfs(A, i, j-1, N, M);
    dfs(A, i+1, j+1, N, M);
    dfs(A, i+1, j-1, N, M);
    dfs(A, i-1, j-1, N, M);
    dfs(A, i-1, j+1, N, M);
    return 1;
    
}

int findIslands(vector<int> A[], int N, int M) {

    int NumIslands = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            NumIslands += dfs(A, i, j, N, M);
        }
    }
    return NumIslands;
}

