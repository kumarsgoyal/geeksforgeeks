#include <stdlib.h>
int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
	//code
	int t = 0;
	scanf("%d", &t);
	while(t--) {
	    int size = 0;
	    
	    scanf("%d", &size);
	    
	    int *a = (int *)calloc(sizeof(int), size);
	    
	    for(int i = 0 ; i < size; i++) {
	        scanf("%d", &a[i]);
	    }
	    
	    int k = 0;
	    scanf("%d", &k);
	    qsort(a, size, sizeof(int), cmp);
	    
	    printf("%d", a[k - 1]);
	    printf("\n");
	}
	return 0;
}
