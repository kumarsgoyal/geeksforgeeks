#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t = 0;
	cin >> t;
	
	while(t--) {
	    int size = 0;
	    map<int, int> mp;
	    
	    cin >> size;
	    
	    int *arr = new int[size];
	    
	    for(int i = 0; i < size; i++) {
	        cin >> arr[i];
	        mp[arr[i]]++;
	    }
	    
	    int max = 0;
	    int res = 0;
	    
	    for(auto i = mp.begin(); i != mp.end(); i++) {
	        if(i->second > max) {
	            max = i->second;
	            res = i->first;
	        }
	    }
	    
	    if(max > size/2) {
	        cout<<res<<endl;
	    }
	    else {
	        cout<<-1<<endl;
	    }
	    
	    
	}
	
	return 0;
}
