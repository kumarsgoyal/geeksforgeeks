#include <bits/stdc++.h>
using namespace std;

int main() {
	int t = 0;
	cin>> t;
	while(t--) {
	    int k, n; // k is kth largest and n is size
	    priority_queue<int, vector<int>, greater<int>> que;
	    cin>>k>>n;
	    int num;
	    int size = 0; // size of max heap
	    for(int i = 1; i <= n; i++) {
	        cin>>num;
	        if(size < k) {
	            que.push(num);
	            size++;
	            if(size == k) {
	                cout<<que.top()<<" ";
	            }
	            else {
	                cout<<-1<<" ";
	            }
	        }
	        else if(size == k && que.top() < num) {
	            que.pop();
	            que.push(num);
	            cout<<que.top()<<" ";
	        }
	        else {
	            cout<<que.top()<<" ";
	        }
	    }
	    cout<<endl;
	}
	return 0;
}
