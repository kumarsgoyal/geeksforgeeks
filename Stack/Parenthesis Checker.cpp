#include <bits/stdc++.h> 

using namespace std;

int main() {
	int t = 0;
	cin >> t;
	while(t--) {
    	string str;
    	cin>> str;
    	stack<char> stk;
    	int i = 0; // index;
    	int flag = 1;
    	
    	while(str[i] != '\0') {
    	    
    	    if(str[i] == '[' || str[i] == '{' || str[i] == '(') {
    	        stk.push(str[i]);
    	    }
    	    else {
    	        if(stk.empty()) {
    	            flag = 0;
    	        }
    	        else {
    	            if((str[i] == ']' && stk.top() == '[') || 
    	            (str[i] == '}' && stk.top() == '{') || 
    	            (str[i] == ')' && stk.top() == '(')) {
    	                stk.pop();
    	            }
    	            else {
    	                flag = 0;
    	            }
    	        }
    	    }
    	    if(flag == 0) {
    	        break;
    	    }
    	    i++;
    	}
    	if(flag == 1 && stk.empty()) {
    	    cout<<"balanced\n";
    	}
    	else {
    	    cout<<"not balanced\n";
    	}
    	
	}
	return 0;
}
