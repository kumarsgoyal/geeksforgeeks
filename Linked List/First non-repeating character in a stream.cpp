#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int test_case = 0;
	cin>>test_case;
	
	while(test_case--) {
	    
	    int size = 0;
	    cin>>size;
	    char ch;
	    
	    int chfreq[26] = {0};
	    queue<char> que;
	    
	    for(int i = 0; i < size; i++) {
	        cin>>ch;
	        
	        chfreq[ch - 'a'] += 1;
	        
	        que.push(ch);
	        
	        
	        while(!que.empty()) {
	            
	            // If it's frequency>1 it can't be non repeating
	            // pop it out and try next one
	            if(chfreq[que.front() - 'a'] > 1) {
	                que.pop();
	            }
	            // element is non repeating print and break loop
	            else {
	                cout<<que.front()<<" ";
	                break;
	            }
	        }
	        
	        // if element is not find in que that means now que is empty
	        
	        if(que.empty()) {
	            cout<<-1<<" ";
	        }
	        
	    }
	    
	    cout<<endl;
	}
	
	return 0;
}
