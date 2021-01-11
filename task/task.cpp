#include "task.h"

tcb_t task_blocks[TASK_NUM];

int current_task_id;

void initialize_multitasking(int task_id)
{
    initialize_multitasking(&task_blocks[task_id]);

    current_task_id = task_id;
}

void switch_to_task(int task_id)
{
    switch_to_task(&task_blocks[task_id], &task_blocks[current_task_id]);

    current_task_id = task_id;
}
