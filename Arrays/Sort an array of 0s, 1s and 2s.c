#include <stdio.h>

int main() {
	int t = 0;
	
	scanf("%d", &t);
	
	while(t--) {
	    int size = 0;
	    int c1 = 0, c2 = 0, c3 = 0;
	    scanf("%d", &size);
	    
	    int *a = (int *)calloc(sizeof(int), size);
	    for(int i = 0; i < size; i++) {
	        scanf("%d", &a[i]);
	        if(a[i] == 0) {
	            c1++;
	        }
	        else if(a[i] == 1) {
	            c2++;
	        }
	        else {
	            c3++;
	        }
	    }
	    for(int i = 0; i < c1; i++) {
	        a[i] = 0;
	    }
	    for(int i = c1; i < c1+c2; i++) {
	        a[i] = 1;
	    }
	    for(int i = c1+c2; i < c1+c2+c3; i++) {
	        a[i] = 2;
	    }
	    for(int i = 0; i < size; i++) {
	        printf("%d ", a[i]);
	    }
	    printf("\n");
	}
	return 0;
}
