#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main(){

    FILE *f1,*f2,*f3,*f4;
    int start,locctr;
    char label[20],opcode[20],operand[20], code[20], mneumonic[20];
    f1 = fopen("Input.txt", "r");
    f2 = fopen("OPTAB.txt", "r");
    f3 = fopen("SYMTB.txt","w");
    f4 = fopen("Out.txt","w");

    // read 1st input statement
    fscanf(f1,"%s\t%s\t%s",label,opcode,operand);
    // if start - set locctr
    if(strcmp(opcode,"START")==0){
        start = atoi(operand);
        locctr=start;
        // write line to intermediate file
        fprintf(f4,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
        // read next input line
        fscanf(f1,"%s\t%s\t%s",label,opcode,operand);
    }
    else locctr=0;

    // not end of input
    while(strcmp(opcode,"END")!=0){

        // print locctr
        fprintf(f4, "%d\t", locctr);

        // if symbol not in symtab add label, locctr
        if(strcmp(label,"**")!=0){
            fprintf(f3, "%s\t%d\n", label,locctr);
        }
        
        // opcode
        fscanf(f2,"%s\t%s",code,mneumonic);
        while(strcmp(code,"END")!=0){
            if(strcmp(opcode, code) == 0){
                locctr+=3;
                break;
            }
            fscanf(f2,"%s\t%d",code,mneumonic);
        }

        if (strcmp(opcode, "WORD") == 0) locctr+=3;
        else if (strcmp(opcode, "RESW") == 0) locctr += 3*atoi(operand);
        else if (strcmp(opcode, "RESW") == 0) locctr+= atoi(operand);
        else if (strcmp(opcode, "BYTE") == 0) locctr+= 1;

        // write line to intermediate file
        fprintf(f4,"%s\t%s\t%s\n",label,opcode,operand);
        // read next input line
        fscanf(f1,"%s\t%s\t%s",label,opcode,operand);
    }

    fprintf(f4, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand); 
    int length = locctr - start;
    printf("Length: %d",length);
    _fcloseall();
}