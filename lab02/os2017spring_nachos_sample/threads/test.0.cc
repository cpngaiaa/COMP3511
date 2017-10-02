

/////////////////////////////////////////////////////////////////////////
//  Test the lock
//

#include "list.h"
#include "system.h"
#include "synch.h"
#include "testcase.h"

Lock *lock;

void  Demo( int i)
{
    printf(" %s is attempting to acquire the lock \n",currentThread->getName());
    lock->Acquire();
    printf(" %s has acquired the lock \n",currentThread->getName());
    currentThread->Yield();
    lock->Release();
    printf(" %s has released the lock \n",currentThread->getName());

}


void SynchTest0()
{
    scheduler->SetSchedPolicy(SCHED_FCFS);
    lock = new Lock("lock");
    Thread *t_1 = new Thread("one");
    Thread *t_2 = new Thread("two");
    Thread *t_3 = new Thread("three");
    Thread *t_4 = new Thread("four");

    t_1->Fork(Demo,1);
    t_2->Fork(Demo,1);
    t_3->Fork(Demo,1);
    t_4->Fork(Demo,1);

}
