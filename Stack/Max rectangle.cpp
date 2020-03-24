// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int maxArea(int M[MAX][MAX], int n, int m);
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        cout << maxArea(M, n, m) << endl;
    }
}
// } Driver Code Ends
/*You are required to complete this method*/
int maxArea(int M[MAX][MAX], int n, int m) {
    int *arr = new int[m];
    int maxg = 0; 
    
    for(int i = 0; i < m; i++) {
        arr[i] = 0;
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(M[i][j] == 0) {
                arr[j] = M[i][j];
            }
            else {
                arr[j] = M[i][j] + arr[j];
            }
        }
        
        stack<int> stk;
        int area = 0;
        int maxl = 0;
        
        for(int j = 0; j < m; j++) {
            
            while(!stk.empty() && arr[stk.top()] > arr[j]) {
                int top = stk.top();
                stk.pop();
                
                int dist = (stk.empty()) ?
                    j : j - stk.top() - 1;
                
                    area = dist * arr[top];
                    maxl = max(maxl, area);
            }
            
            stk.push(j);
            
        }
        
        while(!stk.empty()) {
            int top = stk.top(); 
            stk.pop();
                    
            int dist = (stk.empty()) ?
                m : m - stk.top() - 1;
               
                area = dist * arr[top];
                maxl = max(maxl, area);
        }
        
        maxg = max(maxg, maxl);
    }
    
    return maxg;
}
