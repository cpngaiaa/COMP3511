#include <stdio.h>

void foo(int count){
	int i;


	printf("In foo function\n");
	printf("Count = %i\n",count);

	printf("Numbers:");
	for (i = 1; i <= count; i++){
		printf("\t%i", i);
	}
	printf("\n");
}

