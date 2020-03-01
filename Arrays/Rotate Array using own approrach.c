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
      
	    if(d >= size) {
	        d = d % size;
	    }
	    for(int i = 0; i < size; i++) {
	        scanf("%d", &a[(i + size - d) % size]);
	    }
      
	    for(int i = 0; i < size; i++) {
	        printf("%d ", a[i]);
	    }
	    printf("\n");
	}
	return 0;
}
