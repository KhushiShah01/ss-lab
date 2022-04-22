#include<stdio.h>

int main() {

    int refString[20], p, f, pageFaults=0, flag, min,move=0, 
    repIndex, leastCount;
    int i,j;

    printf("\nLFU PAGE REPLACEMENT\n");
    printf("Enter number of frames: ");
    scanf("%d",&f);
    printf("Enter number of pages: ");
    scanf("%d",&p);
    printf("Enter reference string: ");
    for(i=0; i<p; i++) 
        scanf("%d",&refString[i]);

    int frames[f], counter[f];
    for(i=0; i<f; i++) {
        counter[i] = 0;
        frames[i] = -1;
    }

    for(i=0; i<p; i++) {
        flag = 0;
        for(j=0; j<f; j++) {
            // if hit
            if(refString[i] == frames[j]) {
                flag=1;
                counter[j]++;
                break;
            }
        }
        
        if(flag==0 && pageFaults < f) {
            frames[move] = refString[i];
            counter[move] = 1;
            move = (move+1)%f;
            pageFaults++;
        }
        else if(flag==0) {
            repIndex = 0;
            leastCount = counter[i];
            for(j=1; j<f; j++) {
                if(counter[j] < leastCount) {
                    repIndex = j;
                    leastCount = counter[j];
                }
            }
            frames[repIndex] = refString[i];
            counter[repIndex] = 1;
            pageFaults++;
        }
        printf("\n");
        for(j=0; j<f; j++) 
            printf("%d\t",frames[j]);
    }

    printf("\n\nTotal page faults: %d\n\n",pageFaults);

    return 0;
}
