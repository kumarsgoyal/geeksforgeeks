#include <iostream>
using namespace std;

int main() {
	int test_case = 0;
	cin>>test_case;
	
	while(test_case--) { 
	    int size = 0;
	    cin>>size;
	    // Array

	    int *Arr = new int[size];
	    int *temp = new int[size];
	    for(int i = 0; i < size; i++) {
	      cin>>Arr[i];
	      temp[i] = 1;
	    }
	    
	    for(int i = 1; i < size; i++) {
	        for(int j = 0; j < i; j++) {
	            if((Arr[j] < Arr[i]) && temp[i] < temp[j]+1) {
	                temp[i] = temp[j]+1;
	            }
	        }
	    }
	    int max = 0;
	    for(int i = 0;i < size; i++) {
	        if(temp[i] > max) {
	            max = temp[i];
	        }
	    }
	    
	    
	    
	    cout<<max<<" \n";
	}
	return 0;
}
