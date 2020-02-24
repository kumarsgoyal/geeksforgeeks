#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int test_case = 0;
    scanf("%d", &test_case);
    
    while(test_case--) {
        int v = 0, e = 0;
        scanf("%d %d", &v, &e);
        
        int *vertex = (int *)malloc(sizeof(int) * v);
        for(int i = 0; i < v; i++) {
            vertex[i] = i;
        }
        int *arr1 = (int *)malloc(sizeof(int) * e);
        int *arr2 = (int *)malloc(sizeof(int) * e);
        
        for(int i = 0; i < e; i++) {
            scanf("%d %d", &arr1[i], &arr2[i]);
        }
        
        for(int i = 0; i < v; i++) {
            printf("%d", vertex[i]);
            for(int j = 0; j < e; j++) {
                if(arr1[j] == i) {
                    printf("-> %d", arr2[j]);
                }
                else if(arr2[j] == i) {
                    printf("-> %d", arr1[j]);
                }
            }
            printf("\n");
        }
        
    }
	return 0;
}
