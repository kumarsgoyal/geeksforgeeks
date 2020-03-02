// using max heap

#include <bits/stdc++.h>
using namespace std;
// using max heap


void heapify(int *arr, int size, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    if((left < size) && (arr[left] > arr[largest])) {
        largest = left;
    }
    if((right < size) && (arr[right] > arr[largest])) {
        largest = right;
    }
    
    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}

void buildHeap(int *arr, int n) {
    for(int i = n/2 - 1; i >= 0; i--) {
        
       heapify(arr, n, i);
    }
    
}

void kLargestElement(int *arr, int n) {
    buildHeap(arr, n);
    
    for(int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
	int t = 0;
	cin>> t;
	while(t--) {
	    int size = 0, k = 0;
	    cin>>size>>k;
	    
	    int *arr = new int[size];
	    
	    for(int i = 0; i < size; i++) {
	        cin>>arr[i];
	    }
	    
	    kLargestElement(arr, size);
	    
	    for(int i = size-1; i >= size-k; i--) {
	        cout<<arr[i]<<" ";
	    }
	    cout<<"\n";
	    
	}
	
	return 0;
}
