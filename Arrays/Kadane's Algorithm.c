#include <stdio.h>
#include <stdlib.h>

int main() {
	int t = 0;
	scanf("%d", &t);
	
	while(t--) {
	    
	    int size = 0;
	    scanf("%d", &size);
	    
	    int *a = (int *)calloc(sizeof(int), size);
	    
	    for(int i = 0; i < size; i++) {
	        scanf("%d", &a[i]);
	    }
	    
	    int sum = a[0], max = a[0];
	    
	    for(int i = 1; i < size; i++) {
	        
	        // if prev sum is increasing curr val then add it into
	        // sum else curr element is sum
	        if((a[i] + sum) > a[i]) {
	            sum = sum + a[i];
	        }
	        else {
	            sum = a[i];
	        }
	        
	        // if current sum is greater than max, max is sum
	        if(sum > max) {
	            max = sum;
	        }
	    }
	    printf("%d\n", max);
	    
	}
	return 0;
}
