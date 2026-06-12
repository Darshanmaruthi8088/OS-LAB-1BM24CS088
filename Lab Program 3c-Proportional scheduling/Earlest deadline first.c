#include<stdio.h>
int main(){
    int n;
    printf("Enter the number of process: ");
    scanf("%d",&n);
    int share[n];
    int totalshare=0;
    for(int i=0;i<n;i++){
        printf("Enter the share of %d Process: ",i+1);
        scanf("%d",&share[i]);
        totalshare+=share[i];
    }
    printf("\nProportional scheduling: \n");
    for(int i=0;i<n;i++){
        printf("Process %d has %.2f%% CPU\n",i+1,((float)share[i]/totalshare)*100);
    }
}