#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{ 
    int x; 
    x=0; 
    if ( fork() ) { 
	x=x+1; /* A part */ 
	printf("A produces %2d\n", x);
    } 
    else { 
	x=x+1; /* B part */ 
	printf("B produces %2d\n", x);
    } 
} 

