// { Driver Code Starts
#include<bits/stdc++.h>


#define N 100
using namespace std;

int *mergeKArrays(int arr[][N],int k);

void printArray(int arr[], int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    int arr[N][N];
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	int *output = mergeKArrays(arr, k);
	printArray(output, k*k);
	cout<<endl;
}
	return 0;
}// } Driver Code Ends
// your task is tocomplete this function
// function should return an pointer to output array int*
// of size k*k

struct key {
    int element;
    int arrindex;
    int index;
    bool operator<(const key &k) const
    { 
        return element > k.element; 
    }
};

int *mergeKArrays(int arr[][N], int k)
{
    priority_queue<key> que;
    int *res = new int[k*k];
    int index = 0;
    for(int i = 0; i < k; i++) {
        que.push(key{arr[i][0], i, 0});
    }
    
    while(!que.empty()) {
        key temp = que.top();
        que.pop();
        
        res[index++] = temp.element;
        
        if(temp.index+1 < k) {
            que.push(key{arr[temp.arrindex][temp.index+1], temp.arrindex, temp.index+1});
        }
    }
    
    return res;
}
