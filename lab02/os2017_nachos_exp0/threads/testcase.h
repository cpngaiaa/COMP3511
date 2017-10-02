// testcase.h 

#ifndef TESTCASE_H
#define TESTCASE_H

typedef struct { int burst; int prior;} schedpair ;

void SynchTest0();
void ThreadTest0();
void SynchTest1();
void SynchTest2();
void ThreadTest3();
void ThreadTest4();

void TestScheduler( int );
#endif // TESTCASE_H
