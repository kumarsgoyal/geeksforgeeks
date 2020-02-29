#include <stdio.h>

int main() {
	int t = 0;
	
	scanf("%d", &t);
	
	while(t--) {
	    
	    int size = 0, sum = 0, temp = 0, flag = 0;
	    scanf("%d", &size);
	    scanf("%d", &sum);
	    
	    int *a = (int *)calloc(sizeof(int), size);
	    
	    for(int i = 0; i < size; i++) {
	        scanf("%d", &a[i]);
	    }
	    
	    int p1 = 0, p2 = 0; // indexes
	    temp = a[0];
	    while((p1 < size) && (p2 < size)) {
	        if(temp == sum) {
	            printf("%d %d\n", (p1+1), (p2+1));
	            flag = 1; 
	            break;
	        }
          
          // if temp is less required sum then move p2 in right direction as
          // greater element is present on right side
	        if(temp < sum) {
	            p2++;
	            temp = temp + a[p2];
	        }
          
          // if temp become greater than sum then subtract smallest element 
          // as move p1 to right side
	        else if(temp > sum) {
	            temp = temp - a[p1];
	            p1++;
	        }
	    }
	    if(flag == 0) {
	        printf("%d\n", -1);
	    }
	}
	
	return 0;
}
