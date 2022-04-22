int findLRU(int time[], int n) {
    int i, minimum=time[0], pos=0;

    for(i=1; i<n; i++) {
        if(time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}


int main() {

    int refString[20], p, f, pageFaults=0;
    int counter=0, flag1=0, flag2=0, pos;
    int i,j;

    printf("\nLRU PAGE REPLACEMENT\n");
    printf("Enter number of frames: ");
    scanf("%d",&f);
    printf("Enter number of pages: ");
    scanf("%d",&p);
    printf("Enter reference string: ");
    for(i=0; i<p; i++) 
    scanf("%d",&refString[i]);

    int time[f], frames[f];
    for(i=0; i<f; i++)
        frames[i] = -1;

    for(i=0; i<p; i++) {
        flag1=flag2=0;
        //Page Hit
        for(j=0; j<f; j++) {
            if(refString[i] == frames[j]) {
                counter++;
                time[j] = counter;
                flag1=flag2=1;
                break;
            }
        }
        //Page fault, free frame
        if(flag1==0) {
            for(j=0; j<f; j++) {
                if(frames[j] == -1) {
                    counter++;
                    pageFaults++;
                    frames[j] = refString[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }
        //Page fault, no free frame
        if(flag2==0) {
            pos = findLRU(time, f);
            counter++;
            pageFaults++;
            frames[pos] = refString[i];
            time[pos] = counter;
        }
        printf("\n");
        for(j=0; j<f; j++) 
            printf("%d\t",frames[j]);
    }
    printf("\n\nTotal page faults: %d\n\n",pageFaults);
    return 0;
}

