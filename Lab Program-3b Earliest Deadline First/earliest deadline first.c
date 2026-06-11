#include <stdio.h>

int main() {
    int n;

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    int ex[n], period[n], rem[n], deadline[n];

    for(int i=0;i<n;i++){
        printf("Task %d Execution Time: ",i+1);
        scanf("%d",&ex[i]);

        printf("Task %d Period: ",i+1);
        scanf("%d",&period[i]);

        rem[i]=0;
        deadline[i]=period[i];
    }

    int hyperperiod = 20;

    printf("\nEDF Scheduling\n");

    for(int time=0; time<hyperperiod; time++){

        for(int i=0;i<n;i++){
            if(time % period[i] == 0){
                rem[i] = ex[i];
                deadline[i] = time + period[i];
            }
        }

        int earliest = -1;

        for(int i=0;i<n;i++){
            if(rem[i] > 0){

                if(earliest == -1 ||
                   deadline[i] < deadline[earliest]){

                    earliest = i;
                }
            }
        }

        if(earliest != -1){
            printf("Time %d -> Task %d\n",
                   time, earliest+1);

            rem[earliest]--;
        }
        else{
            printf("Time %d -> Idle\n", time);
        }
    }

    return 0;
}