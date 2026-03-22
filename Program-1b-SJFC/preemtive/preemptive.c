#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0;
    int AT[20], BT[20], RT[20];
    int CT[20], TAT[20], WT[20];
    int min, index;
    float avgWT=0, avgTAT=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Process P%d Arrival Time: ",i+1);
        scanf("%d",&AT[i]);

        printf("Process P%d Burst Time: ",i+1);
        scanf("%d",&BT[i]);

        RT[i] = BT[i];
    }

    while(completed < n){
        min = 9999;
        index = -1;

        for(i=0;i<n;i++){
            if(AT[i] <= time && RT[i] > 0 && RT[i] < min){
                min = RT[i];
                index = i;
            }
        }

        if(index == -1){
            time++;
        }
        else{
            RT[index]--;
            time++;

            if(RT[index] == 0){
                completed++;

                CT[index] = time;
                TAT[index] = CT[index] - AT[index];
                WT[index] = TAT[index] - BT[index];
            }
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


