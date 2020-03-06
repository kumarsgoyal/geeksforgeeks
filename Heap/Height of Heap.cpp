#include <bits/stdc++.h> 
using namespace std; 
  
int height(int N) 
{ 
    return ceil(log2(N + 1)) - 1; 
} 
  
// driver node 
int main() 
{ 
    int t = 0;
    cin>>t;
    
    while(t--) {
        int size = 0;
        cin>>size;
        for(int i = 0; i < size; i++) {
            int num;
            cin>>num;
        }
        
        cout<<height(size)<<endl;
    }
    
    return 0; 
} 
