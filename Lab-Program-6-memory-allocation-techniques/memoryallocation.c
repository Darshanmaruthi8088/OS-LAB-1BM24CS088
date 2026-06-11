#include<stdio.h>

int main(){

    int nb,np;

    printf("Enter number of memory blocks: ");
    scanf("%d",&nb);

    int block[nb];

    printf("Enter block sizes:\n");
    for(int i=0;i<nb;i++){
        scanf("%d",&block[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d",&np);

    int process[np];

    printf("Enter process sizes:\n");
    for(int i=0;i<np;i++){
        scanf("%d",&process[i]);
    }

    int choice;

    printf("\n1.First Fit\n2.Best Fit\n3.Worst Fit\n");
    printf("Enter choice: ");
    scanf("%d",&choice);

    for(int i=0;i<np;i++){

        int index=-1;

        switch(choice){

        case 1: // First Fit

            for(int j=0;j<nb;j++){
                if(block[j] >= process[i]){
                    index=j;
                    break;
                }
            }
            break;

        case 2: // Best Fit

            for(int j=0;j<nb;j++){

                if(block[j] >= process[i]){

                    if(index==-1 ||
                       block[j] < block[index]){

                        index=j;
                    }
                }
            }
            break;

        case 3: // Worst Fit

            for(int j=0;j<nb;j++){

                if(block[j] >= process[i]){

                    if(index==-1 ||
                       block[j] > block[index]){

                        index=j;
                    }
                }
            }
            break;

        default:
            printf("Invalid Choice\n");
            return 0;
        }

        if(index!=-1){

            printf("Process %d allocated to Block %d\n",
                   i+1,index+1);

            block[index]-=process[i];
        }
        else{

            printf("Process %d not allocated\n",
                   i+1);
        }
    }

    return 0;
}