#include <stdio.h>
#include <string.h>
void getcode1(char* input,char operator, char* reg){
    char temp[100];
    int i=0,j=0;
    while(input[i]!='\0'){
        if(input[i]==operator){
            printf("%c\t%c\t%c\t%c\n",operator,*reg,input[i-1],input[i+1]);
            temp[j-1]=*reg;
            i+=2;
            (*reg)--;
            continue;
        }
        temp[j++]=input[i++];
    }
    temp[++j]='\0';
    strcpy(input,temp);
}
void getcode(char* input){
    char reg='Z';
    getcode1(input,'/',&reg);
    getcode1(input,'*',&reg);
    getcode1(input,'+',&reg);
    getcode1(input,'-',&reg);
    getcode1(input,'=',&reg);
}
void main(){
    char input[100];
    printf("Enter exp:");
    scanf("%s",input);
    getcode(input);
}