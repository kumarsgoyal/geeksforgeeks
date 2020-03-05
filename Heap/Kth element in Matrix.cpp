// { Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;

// A structure to store an entry of heap.  The entry contains
// a value from 2D array, row and column numbers of the value
struct HeapNode {
    int val;  // value to be stored
    int r;    // Row number of value in 2D array
    int c;    // Column number of value in 2D array
};

// A utility function to swap two HeapNode items.
void swap(HeapNode *x, HeapNode *y) {
    HeapNode z = *x;
    *x = *y;
    *y = z;
}

// A utility function to minheapify the node harr[i] of a heap
// stored in harr[]
void minHeapify(HeapNode harr[], int i, int heap_size)
{
    int l = i*2 + 1;
    int r = i*2 + 2;
    int smallest = i;
    if (l < heap_size && harr[l].val < harr[i].val)
        smallest = l;
    if (r < heap_size && harr[r].val < harr[smallest].val)
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        minHeapify(harr, smallest, heap_size);
    }
}

// A utility function to convert harr[] to a max heap
void buildHeap(HeapNode harr[], int n)
{
    int i = (n - 1)/2;
    while (i >= 0)
    {
        minHeapify(harr, i, n);
        i--;
    }
}

#define MAX 1000
// This function returns kth smallest element in a 2D array mat[][]
int kthSmallest(int mat[MAX][MAX], int n, int k);

 int mat[MAX][MAX];

// driver program to test above function
int main()
{
int t;
cin>>t;
while(t--)
{
    int n;
    cin>>n;


    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        cin>>mat[i][j];
        int r;
        cin>>r;
    cout<<kthSmallest(mat,n,r)<<endl;
}
 // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
  return 0;
}
// } Driver Code Ends
/*You are required to complete this function*/
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    int size = n*n;
    HeapNode *arr = new HeapNode[size];
    int index = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            arr[index].val = mat[i][j];
            arr[index].r = i;
            arr[index].c = j;
            index++;
        }
    }
    
    buildHeap(arr, size);
    for(int i = 0; i < k-1; i++) {
        arr[0].val = INT_MAX;
        minHeapify(arr, 0, size);
    }
    
    return arr[0].val;
}
