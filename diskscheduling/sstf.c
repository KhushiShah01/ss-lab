#include<stdio.h>
#include<stdlib.h>

void main(){
    int track,nreq,head=50,head1=50, distance=0;
    scanf("%d", &track);
    scanf("%d", &nreq);
    int req[nreq], finish[nreq];
    for(int i=0;i<nreq;i++)
        scanf("%d", &req[i]);

    for(int i=0;i<nreq;i++)
        finish[i]=0;

    int n=nreq;
    
    while(n>0){
        int min=999,i,j,diff,index;
        for (i=0;i<nreq;i++){
            diff = abs(head-req[i]);
            if(diff<min && finish[i]==0){
                min=diff;
                index=i; 
            }
        }
        finish[index]=1;
        distance+=min;
        head = req[index];
        printf("%d ->", req[index]);
        n--;   
    }
    printf("\nTotal distance %d", distance);

}