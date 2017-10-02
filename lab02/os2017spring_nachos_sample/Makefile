# Copyright (c) 1992 The Regents of the University of California.
# All rights reserved.  See copyright.h for copyright notice and limitation 
# of liability and disclaimer of warranty provisions.

MAKE = make

all: 
	cd threads; $(MAKE) depend
	cd threads; $(MAKE) nachos
	mv threads/nachos ./
# don't delete executables in "test" in case there is no cross-compiler
clean:
	/bin/sh -c "rm -f */{core,nachos,test0,test1,test2,DISK,*.o}"
	rm nachos

