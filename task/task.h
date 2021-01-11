#ifndef _TASK_H_
#define _TASK_H_

#include "../include/tipi.h"

#define TASK_NUM 10

#define KERNEL_TASK 0

typedef enum 
{
    ready = 0,
    running = 1,
    blocked = 2
} TASK_STATE;

typedef struct tcb_t
{
    u32 esp;
    u32 cr3;
    tcb_t* next_task;
    int task_state;
} tcb_t;

void initialize_multitasking(int task_id = KERNEL_TASK);
void switch_to_task(int task_id);

extern "C" void initialize_multitasking(tcb_t* kernel_task);
extern "C" void switch_to_task(tcb_t* next_task, tcb_t* old_task);

#endif