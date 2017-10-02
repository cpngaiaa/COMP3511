/*
  filename: main.c

  This is a simple program to illustrate the use and processing of command
  line arguments.

  The program is compiled and named lab01. It can be invoked with two
  command line arguments -n and -h.
     -h: If this argument is given, it will print Hello World! on the
         screen.
     -n: This argument is followed by a number e.g., -n 5. The number
     supplied is passed as an argument to the function foo().
     If you forget to supply the number, then the program will
     cause segmentation fault. This is because the processing of
     the command line arguments is not completely correctly
     implemented. You can improve this further by checking for the
     number properly.

*/

#include "main.h"

/* External functions that are used within this program */
extern void foo();
extern int atoi();

int main(int argc, char *argv[]){

    int i, num;

    printf("  In main function\n");
    printf("  %i command line arguments found\n", argc);
    printf("  The command line arguments are:\n");

    for (i = 0; i < argc; i++)
        printf("  %i\t%s\n", i, argv[i]);

    printf("\n\n");

    if ( argc == 1){
        printf("Usage: lab01 -h -n <number>\n");
        exit(0);
    }

        /* Process Command Line Arguments */
    printf("  Now processing command line arguments\n\n");

    /* This is just an example of how you can process command
     * line arguments. This is not foolproof and cannot detect
     * errors. For example if you type -n5 it will abort. But
     * this is just a starting point for you to develop very
     * sophisticated command line processing code.
     */

    for( i = 1; i < argc; i++ )
    {
        if(argv[i][0] == '-') /* The first char in the argument
                     should always be - */
        {
            switch(argv[i][1])
            {
            case 'h' :
                printf("  found -h!\n");
                printf("  Hello World!\n");
                break;
            case 'n' :
                printf("  found -n!\n");

                /* Here we should check to see if
                   the next argument is a number
                   This is not perfect.
                 */

                if ( i == (argc-1) ) { /* missing number */
                    printf("  Incorrect Arguments %s\n",argv[i]);
                    printf("Usage: lab01 -h -n <number>\n");
                    exit(0);
                }
                if(argv[i+1][0] == '-') {
                /* The first char in the next argument
                   is a -
                 */
                    printf("  Incorrect Arguments %s\n",argv[i]);
                    printf("Usage: lab01 -h -n <number>\n");
                    exit(0);
                }

                i++;

                num = atoi(argv[i]);

                foo(num);

                break;
            default :
                printf("  Unknown option %s\n",argv[i]);
            }
        }
        else { /* first char in argument is not - */
            printf("  Unknown option %s\n",argv[i]);
            printf("Usage: lab01 -h -n <number>\n");
            exit(0);
        }
    }

    return 1;
}
