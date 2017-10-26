#include <pthread.h>
#include <stdio.h>

int sum; /* shared by the threads */
void *runner(void *param); /* threads call this function */

int main(int argc, char *argv[]) {
	pthread_t tid;
	pthread_attr_t attr; 
	int value;

	if (argc != 2) {
		fprintf(stderr, "Usage: pthread_demo <int>\n");
		return 0;
	}

	value = atoi(argv[1]);
	if ( value < 0 ) {
		fprintf(stderr, "%d must be >=0\n", value);
		return -1;
	}

	pthread_attr_init(&attr); // init the default attributes
	pthread_create(&tid, &attr, runner, argv[1]); // create the thread
	pthread_join(tid, NULL); // wait for the thread to exit

	printf("sum of 1..%d = %d\n", value, sum);
}

void *runner(void *param) {
	int i, upper = atoi(param);
	sum = 0; // initialize "sum" shared by thread(s)
	for (i=1; i<=upper; i++)
		sum += i;
	pthread_exit(0); // exit the thread
}
