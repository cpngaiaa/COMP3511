SRCS = main.c numprint.c
HDRS = main.h
OBJECTS = main.o numprint.o
INCLUDE = -I/usr/local/include
LIBS = -lm
CC = gcc
CFLAGS = -g -ansi -Wall
EXEC = lab01
all:	$(EXEC)
$(EXEC):	$(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDE) $(LIBS) $(OBJECTS) -o $(EXEC)
clean:
	rm -f $(OBJECTS) $(EXEC) core *~
depend:
	makedepend -- $(CFLAGS) $(INCLUDES) $(SRCS) $(HDRS) -

# DO NOT DELETE THIS LINE - make depend depends on it.
