#include <bits/stdc++.h> 
using namespace std;

void nextLargestElement(unsigned long long *arr, int size) {
    stack<unsigned long long> stk;
    long long *res = new long long[size];
    
    for(int i = 0; i < size; i++) {
        while(!stk.empty() && arr[stk.top()] <= arr[i]) {
            res[stk.top()] = arr[i];
            stk.pop();
        }
        stk.push(i);
    }
    
    while(!stk.empty()) {
        res[stk.top()] = -1;
        stk.pop();
    }
    
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
	    unsigned long long *arr = new unsigned long long[size];
	    for(int i = 0; i < size; i++) {
	        unsigned long long num;
	        cin >> arr[i];
	    }
	    
        nextLargestElement(arr, size);
        free(arr);
	}
	return 0;
}
