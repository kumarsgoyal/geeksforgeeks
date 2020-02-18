/*
SIZE INDEX(answer)
size=1, position=0
------------------------------------------------------------------------------
size=2, position=1
size=3, position=2
size=4, position=1
size=5, position=2
------------------------------------------------------------------------------
size=6, position=2
size=7, position=3
size=8, position=2
size=9, position=3
------------------------------------------------------------------------------
size=10, position=3
size=11, position=4
size=12, position=3
size=13, position=4
------------------------------------------------------------------------------
size=14, position=4
size=15, position=5
size=16, position=4
size=17, position=5
------------------------------------------------------------------------------
size=18, position=5
size=19, position=6
size=20, position=5
size=21, position=6

for odd N : floor( (n-3)/4 )+2
for even N : floor( (n-2)/4 )+1

*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int t = 0;
	scanf("%d", &t);
	while(t--) {
	    // size of array
	    int size = 0;
	    // scan size of array
	    scanf("%d", &size);
	    // dynamically allocation of array
	    int *a = (int *)calloc(sizeof(int), size);
	    // scan element of array
	    for(int i = 0; i < size; i++) {
	        scanf("%d", &a[i]);
	    }
	    if(size == 1) {
	        printf("%d\n", a[0]);
	    }
	    else if((size % 2) != 0) {
	        printf("%d\n",a[(int)floor( (size-3)/4 )+2]);
	    }
        else {
            printf("%d\n",a[(int)floor( (size-2)/4 )+1]);
        }
	}
	return 0;
}
