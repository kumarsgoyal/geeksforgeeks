#include <bits/stdc++.h>
using namespace std;

int main() {
	int t = 0;
	cin>>t;
	while(t--) {
	    priority_queue<int, vector<int>, greater<int>> minheap;
	    int size = 0;
	    int num = 0;
	    
	    cin>>size;
	    for(int i = 0; i < size; i++) {
	        cin>>num;
	        minheap.push(num);
	    }
	    int res = 0;
	    long long int sum = 0;
	    int a, b;
	    while(size >= 2) {
	        a = minheap.top();
	        minheap.pop();
	        b = minheap.top();
	        minheap.pop();
	        res = a + b;
	        sum += res;
	        minheap.push(res);
	        size--;
	    }
	    cout<<sum<<endl;
	}
	return 0;
}
