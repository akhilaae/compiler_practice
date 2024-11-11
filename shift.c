#include <stdio.h>
#include <string.h>

char input[20],stack[20],shift[20],red[20];
int i=0,j=0,z=0,len=0;
void reduce();
void main(){
    printf("Grammar : \nE->E+E\nE->E*E\nE->(E)\nE->id\n");
    printf("Enter string : ");
    scanf("%s",input);
    len=strlen(input);
    strcpy(shift,"SHIFT->");
    strcpy(red,"REDUCE TO E");
    for(i=0,j=0;j<len;i++,j++){
        if(input[j]=='i' && input[j+1]=='d'){
            stack[i]=input[j];
            stack[i+1]=input[j+1];
            stack[i+2]='\0';
            input[j]=' ';
            input[j+1]=' ';
            printf("$%s\t%s$\t%sid\n",stack,input,shift);
            reduce();
        }
        else{
            stack[i]=input[j];
            stack[i+1]='\0';
            input[j]=' ';
            printf("$%s\t%s$\t%ssymbol\n",stack,input,shift);
            reduce();
        }
    }
}
void reduce(){
    for(z=0;z<len;z++){
        if(stack[z]=='i' && stack[z+1]=='d'){
            stack[z]='E';
            stack[z+1]='\0';
            printf("$%s\t%s$\t%s\n",stack,input,red);
            j++;
        }
    }
    for(z=0;z<len;z++){
        if(stack[z]=='E' && stack[z+1]=='+' && stack[z+2]=='E'){
            stack[z]='E';
            stack[z+1]='\0';
            stack[z+2]='\0';
            printf("$%s\t%s$\t%s\n",stack,input,red);
            i=i-2;
        }
    }
    for(z=0;z<len;z++){
        if(stack[z]=='E' && stack[z+1]=='*' && stack[z+2]=='E'){
            stack[z]='E';
            stack[z+1]='\0';
            stack[z+2]='\0';
            printf("$%s\t%s$\t%s\n",stack,input,red);
            i=i-2;
        }
    }
    for(z=0;z<len;z++){
        if(stack[z]=='(' && stack[z+1]=='E' && stack[z+2]==')'){
            stack[z]='E';
            stack[z+1]='\0';
            stack[z+2]='\0';
            printf("$%s\t%s$\t%s\n",stack,input,red);
            i=i-2;
        }
    }
}