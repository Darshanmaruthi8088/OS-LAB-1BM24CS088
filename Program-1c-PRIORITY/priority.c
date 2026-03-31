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

/*
Enter number of processes: 4

Process 1:
Arrival Time: 0
Burst Time: 5
Priority: 2

Process 2:
Arrival Time: 1
Burst Time: 3
Priority: 1

Process 3:
Arrival Time: 2
Burst Time: 8
Priority: 4

Process 4:
Arrival Time: 3
Burst Time: 6
Priority: 3


Process AT  BT  Priority    CT  TAT WT
P1      0   5   2           5   5   0
P2      1   3   1           8   7   4
P4      3   6   3           14  11  5
P3      2   8   4           22  20  12

Average Waiting Time = 5.25
Average Turnaround Time = 10.75

int remainingBT[n];
for(i = 0; i < n; i++)
    remainingBT[i] = BT[i];

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
        current_time++;
    } else {
        remainingBT[idx]--;   // run for 1 unit
        current_time++;

        if(remainingBT[idx] == 0) {
            CT[idx] = current_time;
            TAT[idx] = CT[idx] - AT[idx];
            WT[idx] = TAT[idx] - BT[idx];

            isCompleted[idx] = 1;
            completed++;
        }
    }
}
🔴 Preemptive Output
Process AT  BT  Priority    CT  TAT WT
P1      0   5   2           8   8   3
P2      1   3   1           4   3   0
P3      2   8   4           22  20  12
P4      3   6   3           14  11  5

Average Waiting Time = 5.00
Average Turnaround Time = 10.50*/
