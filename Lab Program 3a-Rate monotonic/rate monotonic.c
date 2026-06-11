#include<stdio.h>
int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int ex[n],rem[n],p[n];
    for(int i=0;i<n;i++){
        printf("Enter the executions and period of time: ");
        scanf("%d%d",&ex[i],&p[i]);
        rem[i]=0;
    }

    int hyperperiod=1;
    for(int i=0;i<n;i++){
        hyperperiod*=p[i];
    }
    for(int time=0;time<hyperperiod;time++){
        for(int i=0;i<n;i++){
            if(time%p[i]==0){
                rem[i]=ex[i];
            }
        }
    
    int highest=-1;
    for(int i=0;i<n;i++){
        if(rem[i]>0){
            if(highest==-1 || p[i]<p[highest]){
                highest=i;
            }
        }
    }
    if(highest!=-1){
        printf("Time %d-> task%d\n",time,highest+1);
        rem[highest]--;

        }
        else{
            printf("Time %d->idle",time);
        }
    }
    return 0;

}