#include <bits/stdc++.h>
using namespace std;

int main() {
	int t = 0;
	cin >> t;
	
	while(t--) {
	    string str;
	    stack<int> stk;
	    int result = 0;
	    cin >> str;

	    stk.push(-1);
	    for(int i = 0; i < str.length(); i++) {
	        if(str[i] == '(') {
	            stk.push(i);
	        }
	        else {
	            stk.pop();
	            
	            if(!stk.empty()) {
	               result = max(result, i - stk.top());
	            }
	            else {
	                stk.push(i);
	            }
	        }
	    }
	    
	    cout<<result<<endl;
	}
	return 0;
}
