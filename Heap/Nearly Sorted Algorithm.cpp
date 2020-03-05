#include <bits/stdc++.h>
using namespace std;

void nearlySorted(int *Arr, int size, int k) {
    priority_queue<int, vector<int>, greater<int>> que;
    int index = 0;
    for(int i = 0; i < size; i++) {
        if(i < k) {
            que.push(Arr[i]);
        }
        else {
            Arr[index++] = que.top();
            que.pop();
            que.push(Arr[i]);
        }
    }
    
    while(!que.empty()) {
        Arr[index++] = que.top();
        que.pop();
    }
}

void printArray(int *Arr, int size) {
    for(int i = 0; i < size; i++) {
        cout<<Arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
	
	int t = 0;
	cin>>t;
	while(t--) {
	    int size = 0, k = 0;
	    cin>>size>>k;
	    
	    int *Arr = new int[size];
	    for(int i = 0; i < size; i++) {
	        cin>>Arr[i];
	    }
	    
	    nearlySorted(Arr, size, k);
	    printArray(Arr, size);
	}
	
	return 0;
}
