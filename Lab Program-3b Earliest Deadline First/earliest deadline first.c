#include <stdio.h>

typedef struct {
    int id;
    int execution;
    int period;
    int deadline;
    int remaining;
} Task;

int main() {
    int n, hyperperiod = 1;

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    Task tasks[n];

    for (int i = 0; i < n; i++) {
        tasks[i].id = i + 1;

        printf("\nTask %d Execution Time: ", i + 1);
        scanf("%d", &tasks[i].execution);

        printf("Task %d Period: ", i + 1);
        scanf("%d", &tasks[i].period);

        tasks[i].remaining = 0;
        tasks[i].deadline = tasks[i].period;

        hyperperiod *= tasks[i].period;
    }

    printf("\n--- Earliest Deadline First Scheduling ---\n");


    for (int time = 0; time < hyperperiod; time++) {

        for (int i = 0; i < n; i++) {
            if (time % tasks[i].period == 0) {
                tasks[i].remaining = tasks[i].execution;
                tasks[i].deadline = time + tasks[i].period;
            }
        }

        int earliest = -1;


        for (int i = 0; i < n; i++) {
            if (tasks[i].remaining > 0) {
                if (earliest == -1 ||
                    tasks[i].deadline < tasks[earliest].deadline) {
                    earliest = i;
                }
            }
        }


        if (earliest != -1) {
            printf("Time %2d -> Task %d\n",
                   time,
                   tasks[earliest].id);

            tasks[earliest].remaining--;
        } else {
            printf("Time %2d -> Idle\n", time);
        }
    }

    return 0;
}


