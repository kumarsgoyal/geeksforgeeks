#include <stdio.h>

int main() {
	//code
	int t = 0;
	scanf("%d", &t);
	while(t--) {
	  int size = 0;
	  int sum = 0;
	  int res = 0;
	  
	  scanf("%d", &size);
	  
	  int *a = (int *)calloc(sizeof(int), (size-1));
	  
	  for(int i = 0; i < (size-1); i++) {
	      scanf("%d", &a[i]);
	      sum = sum + a[i];
	  }
	  
	  
	  // formula for sum of all element
	  // as only one number is missing 
	  // imaginary sum - actual sum give that number
	  res = ((size+1) * (size))/2; 
	  printf("%d\n", (res-sum));
	  
	} 
	return 0;
}
