#include <stdio.h>
#include <stdlib.h>
typedef struct arr {
    int value;
    int index;
}arr;

int cmp(const void *a, const void *b) {
    int l = ((arr *)a)->value; 
    int r = ((arr *)b)->value;  
    return (l - r);
}

int main() {
    int t = 0;
    scanf("%d", &t);
    while(t--) {
        int size = 0;
        scanf("%d", &size);
        arr *a = (arr *)calloc(sizeof(arr), size);
        for(int i = 0; i < size; i++) {
            scanf("%d", &a[i].value);
            a[i].index = i;
        }
        
        qsort(a, size, sizeof(arr), cmp);
         
        int min = a[0].index;
        int max = 0;
        for(int i = 1; i < size; i++) {
            if(a[i].index < min) {
                min = a[i].index;
            }
            else {
                int diff = a[i].index - min;
                if(diff > max) {
                    max = diff;
                }
            }
        }
        printf("%d\n", max);
    }
	return 0;
}
