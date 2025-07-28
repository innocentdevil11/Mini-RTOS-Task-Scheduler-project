#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_TASKS 5

typedef enum {NEW, READY, RUNNING, WAITING, TERMINATED} State;

typedef struct {
    int id, burst_time, remaining_time, priority;
    State state;
} Task;

Task tasks[MAX_TASKS];
int task_count = 0;

void add_task(int id, int burst, int priority) {
    tasks[task_count].id = id;
    tasks[task_count].burst_time = burst;
    tasks[task_count].remaining_time = burst;
    tasks[task_count].priority = priority;
    tasks[task_count].state = READY;
    task_count++;
}

void run_scheduler() {
    printf("Starting Mini-RTOS Simulation...\n");
    int all_done;
    do {
        all_done = 1;
        int highest_priority = 999, selected = -1;
        for (int i = 0; i < task_count; i++) {
            if (tasks[i].state != TERMINATED && tasks[i].priority < highest_priority) {
                highest_priority = tasks[i].priority;
                selected = i;
            }
        }

        if (selected != -1) {
            all_done = 0;
            tasks[selected].state = RUNNING;
            printf(">> Task %d running\n", tasks[selected].id);
            sleep(1);
            tasks[selected].remaining_time--;

            if (tasks[selected].remaining_time == 0) {
                tasks[selected].state = TERMINATED;
                printf("<< Task %d completed\n", tasks[selected].id);
            } else {
                tasks[selected].state = READY;
            }
        }
    } while (!all_done);
}

int main() {
    add_task(1, 3, 2);
    add_task(2, 4, 1);
    add_task(3, 2, 3);

    run_scheduler();
    return 0;
}
