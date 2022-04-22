#include<stdio.h>
#include<conio.h>
# define max 30


void main(){
    int i,j,n,at[max],bt[max],wt[max],tat[max],temp[max];
    float awt=0,atat=0;
    printf("Enter no of processes: ");
    scanf("%d", &n);

    printf("Burst time and arrival time");
    for(i=0;i<n;i++){
        scanf("%d %d",&bt[i],&at[i]);
    }

    printf("Process\tBurst time\tArrival time\tWaiting time\tTurn around time\n ");
    temp[0]=0;
    for(i=0;i<n;i++){
        wt[i]=0;
        tat[i]=0;
        temp[i+1]=temp[i]+bt[i];
        wt[i]=temp[i]-tat[i];
        tat[i]=wt[i]+bt[i];
        awt+=wt[i];
        atat+=tat[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],at[i],wt[i],tat[i]);
    }
    awt/=n;
    atat/=n;
    printf("Average waiting time = %d\nAverage TAT = %d\n ",awt,atat);

}