#include <stdio.h>

int main() {
	int t = 0;
	scanf("%d", &t);
	
	while(t--) {
	    int size = 0, sum = 0, left_sum = 0, right_sum = 0, flag = 0;
	    scanf("%d", &size);
	    
	    int *a = (int *)calloc(sizeof(int), size);
	    
	    for(int i = 0; i < size; i++) {
	        scanf("%d", &a[i]);
	        sum = sum + a[i];
	    }
	    if(size == 1) {
	        printf("%d\n", 1);
	    }
	    else {
    	    left_sum = a[0];
    	    for(int i = 1;i < size; i++) {
    	        right_sum = sum - left_sum - a[i];
    	        if(right_sum == left_sum) {
    	            printf("%d\n", (i+1));
    	            flag = 1;
    	            break;
    	        }
    	        else {
    	            left_sum = left_sum + a[i];
    	        }
    	    }
    	    
    	    if(flag == 0) {
    	        printf("%d\n", -1);
    	    }
	   }
	    
	}
	return 0;
}
