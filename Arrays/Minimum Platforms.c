#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int t = 0;
	scanf("%d", &t);
	
	while(t--) {
	    
	    int size = 0, max = 0, temp = 0;
	    scanf("%d", &size);
	    
	    int *a = (int *)calloc(sizeof(int ), size);
	    int *d = (int *)calloc(sizeof(int ), size);
	    
	    int *res = (int *)calloc(sizeof(int ), 2361);
	    
	    for(int i = 0; i < size; i++) {
	        scanf("%d", &a[i]);
	    }
	    
	    for(int i = 0; i < size; i++) {
	        scanf("%d", &d[i]);
	    }
	    
	    for(int i = 0; i < size; i++ ) {
	        res[a[i]] += 1;
	        res[d[i] + 1] -= 1;
	    }
	    
	    for(int i = 0; i < 2361; i++) {
	        temp = temp + res[i];
	        if(temp > max) {
	            max = temp;
	        }
	    }
	    printf("%d\n", max);
	}
	
	return 0;
}
