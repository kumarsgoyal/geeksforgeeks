#include <stdio.h>
#include <stdlib.h>

typedef struct arr {
    int buy;
    int sell;
} arr;

int main() {
	int t = 0;
	scanf("%d", &t);
	
	while(t--) {
	    
	    int size = 0;
	    scanf("%d", &size);
	    
	    int *a = (int *)calloc(sizeof(int), size);
	    
	    arr *b  = (arr *)calloc(sizeof(arr), (size/2));
	    
	    for(int i = 0; i < size; i++) {
	        scanf("%d", &a[i]);
	    }
	    
	    
	    int i = 0, count = 0;
	    while(i < (size-1)) {
	        
	        while(i < (size-1) && a[i+1] <= a[i]) {
	            i++;
	        }
	        
	        if(i == (size-1)) {
	            break;
	        }
	        
	        b[count].buy = i++;
	        
	        
	        while((i < size) && (a[i] >= a[i-1])) {
	            i++;
	        }
	        b[count].sell = i-1;
	        
	        count++;
	    }
	    if(count == 0) {
	        printf("No Profit");
	    }
	    else {
	        for(int i =0; i < count; i++) {
	            printf("(%d %d) ", b[i].buy, b[i].sell);
	        }   
	    }
	    printf("\n");
	}
	return 0;
}
