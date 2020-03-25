#include <iostream>
using namespace std;

void calculate(int *arr, int no, int &len) {
    int carry = 0;
    
    for(int i = 0; i <= len; i++) {
        int res = arr[i] * no + carry;
        arr[i] = res%10;
        carry = res/10;
    }
    
    while(carry) {
        arr[++len] = carry%10;
        carry = carry/10;
    }
}

int main() {
	
	int t = 0;
	cin >> t;
	
	while(t--) {
	    
	    // you can use char array instead of int
	    int number;
	    cin >> number;
	    
	    int arr[10000] = {0};
	    arr[0] = 1; // factorial of 0 is 1 and factorial of 1 is 1
	    int len = 0;
	    
	    for(int i = 2; i <= number; i++) {
	        calculate(arr, i, len);
	    }
	    
	    for(int i = len; i >= 0; i--) {
	        cout<<arr[i];
	    }
	    cout<<endl;
	    
	}
	
	return 0;
}
