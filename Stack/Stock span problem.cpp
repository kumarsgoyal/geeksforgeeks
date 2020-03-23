
void cal(int arr[], int size) {
    stack<int> stk;
    int *res = new int[size];
    stk.push(0);
    res[0] = 1;
    
    for(int i = 1; i < size; i++) {
        while((!stk.empty()) && (arr[stk.top()] <= arr[i]))  {
            stk.pop();
        }
        res[i] = (stk.empty()) ? i+1 : i-stk.top(); 
        stk.push(i);
    }
    for(int i = 0; i < size; i++) {
        cout<<res[i]<<" ";
    }
}

int main() {
	int t = 0;
	cin>>t;
	while(t--) {
	    int size = 0;
	    cin>> size;
	    int *arr = new int[size];
	    for(int i = 0; i < size; i++) {
	        cin>>arr[i];
	    }
	    cal(arr, size);
	    cout<<"\n";
	    free(arr);
	}
	return 0;
}
