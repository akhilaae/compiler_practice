#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int i,j,m,n;
char arr[10][10],f[10],c,br,ch;
void first(char c){
    if(islower(c)){
        f[m++]=c;
    }
    for(int i=0;i<n;i++){
        if(arr[i][0]==c){
            if(arr[i][2]=='$'){
                follow(arr[i][0]);
            }
            else if(islower(arr[i][2])){
                f[m++]=arr[i][2];
            }
            else{
                first(arr[i][2]);
            }
        }
    }
}
void follow(char c){
    if(arr[0][0]==c){
        f[m++]='$';
    }
    for(int i=0;i<n;i++){
        for(int j=2;j<strlen(arr[i]);j++){
            if(arr[i][j]==c){
                if(arr[i][j+1]!='\0'){
                    first(arr[i][j+1]);
                }
                if(arr[i][j+1]=='\0' && c!=arr[i][0]){
                    follow(arr[i][0]);
                }
            }
        }
    }
}
void main(){
    printf("Number of productions : ");
    scanf("%d",&n);
    printf("productions : \n");
    for(int i=0;i<n;i++){
        scanf("%s%c",arr[i],&br);
    }
    do{
        ch=0;
        printf("Enter non-terminal : ");
        scanf("%c",&c);
        m=0;
        printf("First(%c) : {",c);
        first(c);
        for(int i=0;i<m;i++){
            printf("%c ",f[i]);
        }
        printf("}\n");
        strcpy(f," ");
        m=0;
        printf("Follow(%c) : {",c);
        follow(c);
        for(int i=0;i<m;i++){
            printf("%c ",f[i]);
        }
        printf("}\n");
        printf("Continue?(1/0) : ");
        scanf("%d%c",&ch,&br);
    }while(ch==1);
}