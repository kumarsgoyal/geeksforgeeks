#include<bits/stdc++.h>
using namespace std;
#define MAX 501

int getId(int M[MAX][MAX],int n);

int main()
{
    int T;
    cin>>T;
    int M[MAX][MAX];
    while(T--)
    {
        int N;
        cin>>N;
        memset(M,0,sizeof M);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>M[i][j];
            }
        }
        cout<<getId(M,N)<<endl;

    }
}

// } Driver Code Ends
// The task is to complete this function

// M[][]: input matrix
// n: size of matrix (n*n)
int getId(int M[MAX][MAX], int n)
{
    int size = n;
    if(n >= 3) {
    stack<int> stk;
    
    for(int i = 0; i < n; i++) {
        stk.push(i);
    }
    
    int A, B, C;
    
    A = stk.top();
    stk.pop();
    B = stk.top();
    stk.pop();
    
    size = n-2;
    
    while(size > 1) { 
        if(M[A][B]) {
            A = stk.top();
        }
        else {
            B = stk.top();
        }
        
        stk.pop();
        size--;
    }
    
    C = stk.top();
    stk.pop();
    if(M[C][A]) {
        C = A;
    }
    if(M[C][B]) {
        C = B;
    }
    
    for(int i = 0; i < n; i++) {
        if((i != C) && (M[C][i] || !M[i][C])) {
            return -1;
        }
    }
    
    return C;
    }
    
    else {
        if(M[1][0] && !M[0][1]) {
            return 0;
        }
        else if(M[0][1] && !M[1][0]) {
            return 1;
        }
        else {
            return -1;
        }
    }
}
