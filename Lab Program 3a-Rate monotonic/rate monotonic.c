#include <stdio.h>

typedef struct {
    int id;
    int execution;
    int period;
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


        hyperperiod *= tasks[i].period;
    }

    printf("\n--- Rate Monotonic Scheduling ---\n");


    for (int time = 0; time < hyperperiod; time++) {

        for (int i = 0; i < n; i++) {
            if (time % tasks[i].period == 0) {
                tasks[i].remaining = tasks[i].execution;
            }
        }

        int highest = -1;


        for (int i = 0; i < n; i++) {
            if (tasks[i].remaining > 0) {
                if (highest == -1 ||
                    tasks[i].period < tasks[highest].period) {
                    highest = i;
                }
            }
        }

        if (highest != -1) {
            printf("Time %2d -> Task %d\n",
                   time,
                   tasks[highest].id);

            tasks[highest].remaining--;
        } else {
            printf("Time %2d -> Idle\n", time);
        }
    }

    return 0;
}
