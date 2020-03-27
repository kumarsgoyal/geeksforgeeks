#include <iostream>
using namespace std;


int Gcd(int a, int b) {
    
    if(b == 0) {
        return a;
    }
    
    return Gcd(b, a % b);
}

int main() {
	int t = 0;
	cin >> t;
	
	while(t--) {
	    int size = 0;
	    int d = 0;
	    cin >> size >> d;
	    int *arr = new int[size];
	    
	    for(int i = 0; i < size; i++) {
	        cin >> arr[i];
	    }
	    
	    int gcd = Gcd(size, d);
	    
	    
	    for(int i = 0; i < gcd; i++) {
	        int temp = arr[i];
	        int j = i;
	        
	        while(1) {
	            int  k = j + d;
	            
	            if(k >= size) {
	                k = k % size;
	            }
	            if(k == i) {
	                break;
	            }
	            
	            arr[j] = arr[k];
	            j = k;
	        }
	        
	        arr[j] = temp;
	        
	    }
	    
	    
	    for(int i = 0; i < size; i++) {
	        cout<<arr[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
