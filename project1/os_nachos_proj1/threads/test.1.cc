#include "system.h"
#include "synch.h"
#include "testcase.h"

Condition *condition;
Lock *conditionlock;



void  Demo1( int i)
{   
    conditionlock->Acquire();
    printf("%s is waiting for condition\n",currentThread->getName());
    condition->Wait(conditionlock);
    printf("%s has acquired the condition lock \n",currentThread->getName());
    for (int i=0; i < 5; i++) {
      printf("working...");
      currentThread->Yield();
    }
    printf("\n%s has released the conditon lock \n",currentThread->getName());
    condition->Signal(conditionlock);
    //printf("%s has released the conditon lock \n",currentThread->getName());
    currentThread->Yield();


}


void  Demo3( int i)
{   
    conditionlock->Acquire(); 
    condition->Signal(conditionlock);
    printf("The condition is ok now!! \n");
    currentThread->Yield();
    //printf("%s has released the conditon lock \n",currentThread->getName());

}

void SynchTest1()
{
    scheduler->SetSchedPolicy(SCHED_RR);
    conditionlock = new Lock("condition lock");
    condition = new Condition("condition");
    Thread *t_1 = new Thread("threadone");
    Thread *t_2 = new Thread("threadtwo");
    Thread *t_3 = new Thread("threadthree");
    Thread *t_4 = new Thread("threadfour");


    t_1->Fork(Demo1,1);
    t_2->Fork(Demo1,1);
    t_3->Fork(Demo1,1);
    t_4->Fork(Demo3,1);

}
