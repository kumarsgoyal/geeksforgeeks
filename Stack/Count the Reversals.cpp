#include <bits/stdc++.h>
using namespace std;

int main() {
	int t = 0;
	 cin >> t;
	 
	 while(t--) {
	     string s;
	     cin>>s;
	     
	     stack<char> stk;
	    
	     for(int i = 0; i < s.length(); i++) {
	         if(stk.empty() || s[i] == '{') {
	             stk.push(s[i]);
	         }
	         else {
	             if(stk.top() == '{') {
	                 stk.pop();
	             }
	             else {
	                 stk.push(s[i]);
	             }
	         }
	     }
	     
	     int size = stk.size();
	   
	     if(size%2) {
	         cout<<-1<<endl;
	     }
	     else {
	         int n = 0;
	        while(!stk.empty() && stk.top() == '{') {
	            n++;
	            stk.pop();
	        }
	        
	        cout<<(size/2 + n%2)<<endl;
	     }
	     
	 }
	return 0;
}
