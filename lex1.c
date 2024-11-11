#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int kwd(char buffer[]){
    int flag=0;
    char keyword[32][10]={"if","else","switch","case","default","for","do","while","break","continue","sizeof","typedef","struct","union","int","char","float","double","long","short","auto","const","enum","extern","static","goto","register","return","signed","unsigned","void","volatile"};
    for(int i=0;i<32;++i){
        if(strcmp(keyword[i],buffer)==0){
            flag=1;
            break;
        }
    }
    return flag;
}
void main(){
    FILE* fptr=fopen("lex.txt","r");
    char operators[]="+-*/=;,()",ch,buffer[10];
    int j=0;
    while((ch=fgetc(fptr))!=EOF){
        for(int i=0;i<10;i++){
            if(ch==operators[i] && kwd(buffer)==0){
                printf("id ");
            }
        }
        for(int i=0;i<10;i++){
            if(ch==operators[i]){
                if(operators[i]=='+'){
                    printf("op-plus ");
                }
                else if(operators[i]=='-'){
                    printf("op-sub ");
                }
                else if(operators[i]=='*'){
                    printf("op-mul ");
                }
                else if(operators[i]=='/'){
                    printf("op-div ");
                }
                else if(operators[i]=='='){
                    printf("op-eq ");
                }
                else if(operators[i]==';'){
                    printf(";\n");
                }
                else if(operators[i]==','){
                    printf(", ");
                }
                else if(operators[i]=='('){
                    printf(".");
                }
            }
        }
        if(isalnum(ch)){
            buffer[j++]=ch;
        }
        else if((ch==' '||ch=='\n') && j!=0){
            buffer[j]='\0';
            j=0;
            if(kwd(buffer)==1){
                printf("kwd ");
            }
        }
    }
    fclose(fptr);
}