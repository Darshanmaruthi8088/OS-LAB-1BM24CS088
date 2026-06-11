#include<stdio.h>

int main(){

    int n,f,choice;

    printf("Enter number of pages: ");
    scanf("%d",&n);

    int page[n];

    printf("Enter pages: ");
    for(int i=0;i<n;i++){
        scanf("%d",&page[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d",&f);

    int frame[f];

    for(int i=0;i<f;i++)
        frame[i]=-1;

    printf("\n1.FIFO\n2.LRU\n3.Optimal\n");
    printf("Enter choice: ");
    scanf("%d",&choice);

    int faults=0;

    switch(choice){

    case 1:{

        int ptr=0;

        for(int i=0;i<n;i++){

            int hit=0;

            for(int j=0;j<f;j++){
                if(frame[j]==page[i]){
                    hit=1;
                    break;
                }
            }

            if(!hit){
                frame[ptr]=page[i];
                ptr=(ptr+1)%f;
                faults++;
            }
        }

        printf("FIFO Page Faults = %d",faults);
        break;
    }

    case 2:{

        int time[f];

        for(int i=0;i<f;i++)
            time[i]=0;

        for(int i=0;i<n;i++){

            int hit=0;

            for(int j=0;j<f;j++){

                if(frame[j]==page[i]){
                    hit=1;
                    time[j]=i;
                }
            }

            if(!hit){

                int pos=0;

                for(int j=1;j<f;j++){
                    if(time[j]<time[pos])
                        pos=j;
                }

                frame[pos]=page[i];
                time[pos]=i;
                faults++;
            }
        }

        printf("LRU Page Faults = %d",faults);
        break;
    }

    case 3:{

        for(int i=0;i<n;i++){

            int hit=0;

            for(int j=0;j<f;j++){
                if(frame[j]==page[i]){
                    hit=1;
                    break;
                }
            }

            if(!hit){

                int pos=0;
                int farthest=-1;

                for(int j=0;j<f;j++){

                    int k;

                    for(k=i+1;k<n;k++){
                        if(frame[j]==page[k])
                            break;
                    }

                    if(k>farthest){
                        farthest=k;
                        pos=j;
                    }
                }

                frame[pos]=page[i];
                faults++;
            }
        }

        printf("Optimal Page Faults = %d",faults);
        break;
    }

    default:
        printf("Invalid Choice");
    }

    return 0;
}