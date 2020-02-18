// Using Reversal algo

#include <iostream>
using namespace std;


// reverse array from start to end
void reverse(int arr[], int start, int end) {
    while(start < end) {
        int temp = arr[start]; 
        arr[start] = arr[end]; 
        arr[end] = temp; 
        start++; 
        end--; 
    }
}

// function to rotate array
void rotateArray(int arr[], int d, int n) {
    if(d == 0) {
        return;
    }
    reverse(arr, 0, d-1);
    reverse(arr, d, n-1);
    reverse(arr, 0, n-1);
}


// function to print array
void print(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}


// main
int main() {
	
    int t = 0;
    cin>>t;
    
    while(t--) {
        int size = 0;
        cin>>size;
        
        int *arr = new int[size];
        
        for(int i = 0; i < size; i++) {
            cin>>arr[i];
        }
        
        int d = 0;
        cin>>d;
        
        rotateArray(arr, d, size);
        print(arr, size);
    }
    
 
    
	return 0;
}
