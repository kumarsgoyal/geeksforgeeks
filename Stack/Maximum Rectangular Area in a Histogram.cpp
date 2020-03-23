#include <bits/stdc++.h>
using namespace std;

void findArea(int *arr, int size) {
    stack<int> stk;
    unsigned long long area = 0;
    unsigned long long maxi = 0;
    for(int i = 0; i < size; i++) {
        while(!stk.empty() && arr[stk.top()] > arr[i]) {
                int top = stk.top();
                stk.pop();
                
                unsigned long long dist = (stk.empty()) ?
                    i : i - stk.top() - 1;
                
                area = dist * arr[top];
                
                maxi = max(maxi, area);
        }
        
        stk.push(i);
    }
    
    
    while(!stk.empty()) {
        int top = stk.top();
        stk.pop();
                
        unsigned long long dist = (stk.empty()) ?
            size : size - stk.top() - 1;
                
        area = dist * arr[top];
                
        maxi = max(maxi, area);
    }
    
    cout<<maxi<<endl;
    return;
    
}


int main() {
	int t = 0;
	cin >> t;
	
	while(t--) {
	    int size = 0;
	    cin >> size;
	    int *arr = new int[size];
	    
	    for(int i = 0; i < size; i++) {
	        cin>>arr[i];
	    }
	    
	    findArea(arr, size);
	}
	
	return 0;
}
