  
#include <bits/stdc++.h> 
using namespace std;

void immediateSmallerElement(int *arr, int size) {
    stack<int> stk;
    int *res = new int[size];
    
    stk.push(0);
    for(int i = 1; i < size; i++) {
        if(arr[stk.top()] > arr[i]) {
            res[stk.top()] = arr[i];
        }
        else {
            res[stk.top()] = -1;
        }
        stk.pop();
        stk.push(i);
    }
    
    res[stk.top()] = -1;
    stk.pop();
    
    for(int i = 0; i < size; i++) {
        cout<<res[i]<<" ";
    }
    cout<<"\n";
    free(res);
    
}


int main() {
	int t = 0;
	cin >> t;
	while(t--) {
	    int size = 0;
	    cin>>size;
	    int *arr = new int[size];
	    for(int i = 0; i < size; i++) {
	        cin >> arr[i];
	    }
	    
        immediateSmallerElement(arr, size);
        free(arr);
	}
	return 0;
}

