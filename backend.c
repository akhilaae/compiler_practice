#include <stdio.h>
#include <string.h>
void main(){
    char code[10][20],opr[10],str[30];
    printf("Enter code. stop by exit.\n");
    int i=0;
    do{
        scanf("%s",code[i]);
    }while(strcmp(code[i++],"exit")!=0);
    printf("Target code : \n");
    i=0;
    do{
        strcpy(str,code[i]);
        switch(str[3]){
            case '+':{
                strcpy(opr,"ADD");
                break;
            }
            case '-':{
                strcpy(opr,"SUB");
                break;
            }
            case '*':{
                strcpy(opr,"MUL");
                break;
            }
            case '/':{
                strcpy(opr,"DIV");
                break;
            }
        }
        printf("MOV %c, R%d\n",str[2],i);
        printf("%s %c, R%d\n",opr,str[4],i);
        printf("MOV R%d, %c\n",i,str[0]);
        i++;
    }while(strcmp(code[i],"exit")!=0);
}