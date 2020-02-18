// Using Reversal Algorithm
#include <iostream>
using namespace std;


// function to reverse array from start to end index
void reverse(int arr[], int start, int end) {
    while(start < end) {
        int temp = arr[start]; 
        arr[start] = arr[end]; 
        arr[end] = temp; 
        start++; 
        end--; 
    }
}


// rotate array
void rotateArray(int arr[], int d, int n) {
    if(d == 0) {
        return;
    }
    reverse(arr, 0, n-d-1);
    reverse(arr, n-d, n-1);
    reverse(arr, 0, n-1);
}


// print array
void print(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}


// main()
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
