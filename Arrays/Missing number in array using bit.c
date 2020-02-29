#include <stdio.h>

int main() {
	//code
	int t = 0;
	scanf("%d", &t);
	while(t--) {
	  int size = 0;
	  int actualsum = 0;
	  int imgsum = 0;
	  int res = 0;
	  
	  scanf("%d", &size);
	  
	  int *a = (int *)calloc(sizeof(int), (size-1));
	  
	  for(int i = 0; i < (size-1); i++) {
	      scanf("%d", &a[i]);
	      actualsum = actualsum ^ a[i];
	  }
	  
	  for(int i = 0; i < size; i++) {
	      imgsum = imgsum ^ (i+1);
	  }
	  
	  printf("%d\n", imgsum ^ actualsum);
	  
	} 
	return 0;
}
