#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int test_case = 0;
	cin>>test_case;
	
	while(test_case--) {
	    stack<int> stk;
	    int size = 0;
	    cin>>size;
	    int *Arr = new int[size];
	    
	    for(int i = 0; i < size; i++) {
	        cin>>Arr[i];
	    }
	    
	    int leader = Arr[size-1];
	    for(int i = size-1; i >= 0; i--) {
	        if(Arr[i] >= leader) {
	            stk.push(Arr[i]);
	            leader = Arr[i];
	        }
	    }
	    while(!stk.empty()) {
	        cout<<stk.top()<<" ";
	        stk.pop();
	    }
	    cout<<"\n";
	}
	return 0;
}
