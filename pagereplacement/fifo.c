#include<stdio.h>

int main() {

    int refString[20];
    int pageFaults = 0, s, pages, frames;
    int i,j;

    printf("\nFIFO PAGE REPLACEMENT\n");
    printf("Enter number of frames: ");
    scanf("%d",&frames);
    printf("Enter number of pages: ");
    scanf("%d",&pages);
    printf("Enter reference string: ");
    for(i=0; i<pages; i++) 
        scanf("%d",&refString[i]);

    int temp[frames];
    for(i=0; i<frames; i++)
        temp[i] = -1;
        
    for(i=0; i<pages; i++) {
        s = 0;
        for(j=0; j<frames; j++) {
            if(refString[i] == temp[j]) {
                s++;
                pageFaults--;
            }
        }
        pageFaults++;
        if(pageFaults <= frames && s==0) 
            temp[i] = refString[i];
        else if(s==0) 
            temp[(pageFaults-1)%frames] = refString[i];
        printf("\n");

        for(j=0; j<frames; j++) 
            printf("%d\t", temp[j]);
    }
    printf("\n\nTotal page faults: %d\n\n",pageFaults);
    return 0;
}

