#include <stdio.h>

int main() {
    int n, tq, i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int AT[n], BT[n], RT[n];
    int CT[n], TAT[n], WT[n];

    printf("Enter Arrival Time and Burst Time:\n");
    for(i = 0; i < n; i++) {
        printf("P%d AT: ", i+1);
        scanf("%d", &AT[i]);
        printf("P%d BT: ", i+1);
        scanf("%d", &BT[i]);
        RT[i] = BT[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int completed = 0, current_time = 0;

    while(completed < n) {
        int done = 1;

        for(i = 0; i < n; i++) {
            if(AT[i] <= current_time && RT[i] > 0) {
                done = 0;

                if(RT[i] > tq) {
                    current_time += tq;
                    RT[i] -= tq;
                } else {
                    current_time += RT[i];
                    RT[i] = 0;

                    CT[i] = current_time;
                    completed++;
                }
            }
        }

        if(done)
            current_time++;
    }

    float totalWT = 0, totalTAT = 0;

    printf("\nProcess AT  BT  CT  TAT WT\n");
    for(i = 0; i < n; i++) {
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];

        printf("P%d      %d   %d   %d   %d   %d\n",
               i+1, AT[i], BT[i], CT[i], TAT[i], WT[i]);

        totalWT += WT[i];
        totalTAT += TAT[i];
    }

    printf("\nAverage Waiting Time = %.2f", totalWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", totalTAT / n);

    return 0;
}


/*Enter number of processes: 4

P1 AT: 0
P1 BT: 5
P2 AT: 1
P2 BT: 4
P3 AT: 2
P3 BT: 2
P4 AT: 3
P4 BT: 1

Enter Time Quantum: 2

Process AT  BT  CT  TAT WT
P1      0   5   12  12  7
P2      1   4   11  10  6
P3      2   2   6   4   2
P4      3   1   7   4   3

Average Waiting Time = 4.50
Average Turnaround Time = 7.50*/
