#include <sys/types.h> /* Unix/Linux types */
#include <stdio.h>  /* C Standard Library */
#include <unistd.h> /* POSIX API */

int value = 5;

int main() {
	pid_t pid ;
	pid = fork(); 
	if ( pid == 0 ) { /* child process */
		sleep(1);
		value += 15;
		printf("Child: value = %d\n", value);
	
	} else { /* parent process */
		 wait(NULL); // wait for the child process
		value -= 10;
		printf("Parent: value = %d\n", value);
	}
	return 0;
}
