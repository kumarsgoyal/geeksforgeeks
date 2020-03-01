// rotate element in left direction
#include <stdio.h>
#include <stdlib.h>
int main() {
	//code
	int n = 0;
	scanf("%d", &n);
	while(n--) {
	    int size = 0, d = 0;
	    scanf("%d", &size);
	    scanf("%d", &d);
	    int *a = (int *)calloc(sizeof(int), size);
	    for(int i = 0; i < size; i++) {
	        scanf("%d", &a[i]);
	    }
	    
	    // array reversal algorithm
	    // if size is less than no. of rotate array
	    if(d >= size) {
	        d = d % size;
	    }
	    
	    if(d > 0) {
    	    // reverse 0 to size - d
    	    int i = 0;
    	    int j = d - 1;
    	    int temp;
    	    while(i < j) {
    	        temp = a[i];
    	        a[i] = a[j];
    	        a[j] = temp;
    	        i++;
    	        j--;
    	    }
    	    
    	    // reverse size - d to size
    	    i = d;
    	    j = size - 1;
    	    
    	    while(i < j) {
    	        temp = a[i];
    	        a[i] = a[j];
    	        a[j] = temp;
    	        i++;
    	        j--;
    	    }
    	    
    	    
    	    // reverse whole array
    	    i = 0;
    	    j = size - 1;
    	    while(i < j) {
    	        temp = a[i];
    	        a[i] = a[j];
    	        a[j] = temp;
    	        i++;
    	        j--;
    	    }
	    }
	    for(int i = 0; i < size; i++) {
	        printf("%d ", a[i]);
	    }
	    printf("\n");
	}
	return 0;
}

/*

// to rotate element in right direction
#include <stdio.h>
#include <stdlib.h>
int main() {
	//code
	int n = 0;
	scanf("%d", &n);
	while(n--) {
	    int size = 0, d = 0;
	    scanf("%d", &size);
	    scanf("%d", &d);
	    int *a = (int *)calloc(sizeof(int), size);
	    for(int i = 0; i < size; i++) {
	        scanf("%d", &a[i]);
	    }
	    
	    // array reversal algorithm
	    // if size is less than no. of rotate array
	    if(d >= size) {
	        d = d % size;
	    }
	    
	    
	    // reverse 0 to size - d
	    int i = 0;
	    int j = size - d - 1;
	    int temp;
	    while(i < j) {
	        temp = a[i];
	        a[i] = a[j];
	        a[j] = temp;
	        i++;
	        j--;
	    }
	    
	    // reverse size - d to size
	    i = size - d;
	    j = size - 1;
	    
	    while(i < j) {
	        temp = a[i];
	        a[i] = a[j];
	        a[j] = temp;
	        i++;
	        j--;
	    }
	    
	    
	    // reverse whole array
	    i = 0;
	    j = size - 1;
	    while(i < j) {
	        temp = a[i];
	        a[i] = a[j];
	        a[j] = temp;
	        i++;
	        j--;
	    }
	    
	    for(int i = 0; i < size; i++) {
	        printf("%d ", a[i]);
	    }
	    printf("\n");
	}
	return 0;
}
*/
