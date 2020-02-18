// C++ program to rotate an array by Juggling Algorithm
// d elements to be shift

#include <bits/stdc++.h> 
using namespace std; 
  
/*Fuction to get gcd of a and b*/
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
  
    else
        return gcd(b, a % b); 
} 
  
// function to left rotate arr[] of siz n by d
void leftRotate(int arr[], int d, int n) 
{ 
    int gcd_ = gcd(d, n); 
    for (int i = 0; i < gcd_; i++) { 
        /* move i-th values of blocks */
        int temp = arr[i]; 
        int j = i; 
  
        while (1) { 
            int k = j + d; 
            if (k >= n) 
                k = k % n; 
  
            if (k == i) 
                break; 
  
            arr[j] = arr[k]; 
            j = k; 
        } 
        arr[j] = temp; 
    } 
} 
  
// function to print an array 
void printArray(int arr[], int size) 
{ 
    for (int i = 0; i < size; i++) 
        cout << arr[i] << " "; 
} 
  
// main()
int main() 
{ 

    int t = 0;
    while(t--) {
        int size = 0;
        cin>> size;
        int *arr = new int[size];
        
        for(int i = 0; i < size; i++) {
            cin>>arr[i];
        }
        
        leftRotate(arr, 2, size); 
        printArray(arr, size); 
    }
  
    return 0; 
}
