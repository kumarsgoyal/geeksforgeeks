void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
} 
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    
    int start = low;
    int end = high;
  
    while(start < end) {
        while(arr[start] < pivot) {
            start++;
        }
        while(arr[end] >= pivot) {
            end--;
        }
        if(start < end) {
            swap(&arr[start], &arr[end]);
        }
    }
    swap(&arr[high], &arr[start]);
    return start; 
}
