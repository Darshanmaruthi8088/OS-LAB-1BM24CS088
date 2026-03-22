#include <stdio.h>
int main() {
    int n, i, j;
    int AT[20], BT[20], CT[20], TAT[20], WT[20];
    int completed[20] = {0};
    int current_time = 0, done = 0;
    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i=0;i<n;i++){
        printf("Process P%d Arrival Time: ",i+1);
        scanf("%d",&AT[i]);

        printf("Process P%d Burst Time: ",i+1);
        scanf("%d",&BT[i]);
    }

    while(done < n){
        int minBT = 9999, index = -1;

        for(i=0;i<n;i++){
            if(AT[i] <= current_time && completed[i]==0){
                if(BT[i] < minBT){
                    minBT = BT[i];
                    index = i;
                }
            }
        }

        if(index == -1){
            current_time++;
        }
        else{
            CT[index] = current_time + BT[index];
            TAT[index] = CT[index] - AT[index];
            WT[index] = TAT[index] - BT[index];

            current_time = CT[index];
            completed[index] = 1;
            done++;
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++){
        avgWT += WT[i];
        avgTAT += TAT[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,AT[i],BT[i],CT[i],TAT[i],WT[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avgWT/n);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT/n);

    return 0;
}

