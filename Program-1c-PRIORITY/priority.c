#include <stdio.h>

int main() {
    int n, i, completed = 0, current_time = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int AT[n], BT[n], Priority[n];
    int CT[n], TAT[n], WT[n];
    int isCompleted[n];

    // Input
    for(i = 0; i < n; i++) {
        printf("\nProcess %d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &AT[i]);
        printf("Burst Time: ");
        scanf("%d", &BT[i]);
        printf("Priority: ");
        scanf("%d", &Priority[i]);
        isCompleted[i] = 0;
    }

    // Scheduling
    while(completed < n) {
        int idx = -1;
        int highestPriority = 9999;

        for(i = 0; i < n; i++) {
            if(AT[i] <= current_time && isCompleted[i] == 0) {
                if(Priority[i] < highestPriority) {
                    highestPriority = Priority[i];
                    idx = i;
                }
            }
        }

        if(idx == -1) {
            current_time++;  // CPU idle
        } else {
            CT[idx] = current_time + BT[idx];
            TAT[idx] = CT[idx] - AT[idx];
            WT[idx] = TAT[idx] - BT[idx];

            isCompleted[idx] = 1;
            completed++;
            current_time = CT[idx];
        }
    }

    // Calculate averages
    float totalWT = 0, totalTAT = 0;

    printf("\n\nProcess\tAT\tBT\tPriority\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n",
               i + 1, AT[i], BT[i], Priority[i],
               CT[i], TAT[i], WT[i]);

        totalWT += WT[i];
        totalTAT += TAT[i];
    }

    printf("\nAverage Waiting Time = %.2f", totalWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", totalTAT / n);

    return 0;
}


