#include <bits/stdc++.h>
using namespace std;

void getMinSum(int size) {
    int sum1 = 0, sum2 = 0;
    int num;
    priority_queue<int, vector<int>, greater<int>> que;
    for(int i = 0; i < size; i++) {
        cin>>num;
        que.push(num);
    }
    
    for(int i = 0; i < size; i++) {
        if(i%2) {
            sum1 = (sum1 * 10) + que.top();
        }
        else {
            sum2 = (sum2 * 10) + que.top();
        }
        que.pop();
    }
    cout<<sum1+sum2<<endl;
}

int main() {
	int t = 0;
    cin>>t;
    while(t--) {
        int size = 0;
        cin>>size;
        getMinSum(size);
    }
	return 0;
}
