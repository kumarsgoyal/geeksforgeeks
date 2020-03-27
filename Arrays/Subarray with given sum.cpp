#include <iostream>
using namespace std;

int main() {
	int t = 0;
	cin >> t;
	while(t--) {
	    int size, getsum;
	    cin >> size >> getsum;
	    
	    int *arr = new int[size];
	    
	    for(int i = 0; i < size; i++) {
	        cin >> arr[i];
	    }
	    
	    int sum = arr[0];
	    int flag = 1;
	    int index1 = 0, index2 = 0;
	    while(index1 < size && index2 < size) {
	        
	        if(sum == getsum) {
	            cout<< index1+1<< " "<< index2+1<< endl;
	            flag = 0;
	            break;
	        }
	        
	        if(sum < getsum) {
	            index2++;
	            sum += arr[index2];
	        }
	        else if(sum > getsum) {
	            sum -= arr[index1];
	            index1++; 
	        }
	        
	    }

	    
	    if(flag == 1) {
	        cout<<-1<<endl;
	    }
	}
	return 0;
}
