#include <iostream>
using namespace std;

int main() {
	
	int t = 0;
	cin >> t;
	while(t--) {
	    int size = 0;
	    unsigned long long int actualSum = 0;
	
	    cin>>size;
	    int *arr = new int[size];
	    
	    for(int i = 0; i < size-1; i++) {
	        cin>>arr[i];
	        actualSum += arr[i];
	    }
	    
	    unsigned long long sum = 
	        (((unsigned long long int) size) * (size + 1)) / 2;
	    
	    cout << sum - actualSum<<endl;
	}
	
	return 0;
}
