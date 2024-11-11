#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"
// E->TE'
// E'->+TE'|e
// T->FT'
// T'->*FT'|e
// F->(E)|i
void e();
void t();
void f();
void e_prime();
void t_prime();
void advance();

char input[10],prod[10],temp[10];
int ptr=0,n=0;
void advance(){
    ptr++;
}
void e(){
    strcpy(prod,"TE'");
    printf("E=%-25s",prod);
    printf("E->TE'\n");
    t();
    e_prime();
}
//T->FT'
void t(){
    int i,l,k=0;
    for(i=0;i<=strlen(prod);i++){
        if(prod[i]!='e'){
            temp[k++]=prod[i];
        }
    }
    strcpy(prod,temp);
    l=strlen(prod);
    for(n=0;n<l && prod[n]!='T';n++);
    i=n+1;                      //0 1 2  3 4 //prod[F T '  E ' ]
    do{                             
        prod[i+2]=prod[i];
        i++;
    }while(i<l);
    prod[n++]='F';
    prod[n++]='T';
    prod[n++]=39;
    printf("E=%-25s",prod);
    printf("E->FT'\n");
    f();
    t_prime();
}
// E'->+TE'|e
//     0 1 2  3 4 5 6 7 8
//prod[F T '  E ' ]
void e_prime(){
    int i,l,k=0;
    for(i=0;i<=strlen(prod);i++){
        if(prod[i]!='e'){
            temp[k++]=prod[i];
        }
    }
    strcpy(prod,temp);
    l=strlen(prod);
    for(n=0;n<l && prod[n]!='E';n++);
    if(input[ptr]=='+'){
        i=n+2;                      
        do{                             
            prod[i+2]=prod[i];
            i++;
        }while(i<=l);
        prod[n++]='+';
        prod[n++]='T';
        prod[n++]='E';
        prod[n++]=39;
        printf("E=%-25s",prod);
        printf("E'->+TE'\n");
        advance();
        t();
        e_prime();
    }
    else{
        prod[n++]='e';
        for(i=n;i<=strlen(prod);i++){
            prod[i]=prod[i+1];
        }
        printf("E=%-25s",prod);
        printf("E'->e\n");
    }
    
}
// T'->*FT'|e
void t_prime(){
    int l,k=0,i;
    for(i=0;i<=strlen(prod);i++){
        if(prod[i]!='e')
            temp[k++]=prod[i];
    }
    strcpy(prod,temp);
    l=strlen(prod);
    for(n=0;n<l && prod[n]!='T';n++);
    if(input[ptr]=='*'){
        i=n+2;
        do{
            prod[i+2]=prod[i];
        }while(i<l);
        prod[n++]='*';
        prod[n++]='F';
        prod[n++]='T';
        prod[n++]=39;
        printf("E=%-25s",prod);
        printf("T'->*FT'\ni");
        advance();
        f();
        t_prime();
    }
    else{
        prod[n++]='e';
        for(i=n;i<=strlen(prod);i++){
            prod[i]=prod[i+1];
        }
        printf("E=%-25s",prod);
        printf("T'->e\n");
    }
}
// F->(E)|i
void f(){
    int l=strlen(prod),k=0,i;
    for(i=0;i<=strlen(prod);i++){
        if(prod[i]!='e')
            temp[k++]=prod[i];
    }
    strcpy(prod,temp);
    l=strlen(prod);
    for(n=0;n<l && prod[n]!='F';n++);
    if(input[ptr]=='i' || input[ptr]=='I'){
        prod[n++]='i';
        printf("E=%-25s",prod);
        printf("F->i\n");
        advance();
    }
    else{
        if(input[ptr]=='('){
            advance();
            e();
            if(input[ptr]==')'){
                advance();
                i=n+2;
                do{
                    prod[i+2]=prod[i];
                    i++;
                }while(i<=l);
                prod[n++]='(';
                prod[n++]='E';
                prod[n++]=')';
                printf("E=%-25s",prod);
                printf("T'->(E)\n");
            }
        } 
    }
}
void main()
{
    int i;
    printf("\nGrammar without left recursion\n");
    printf("\n\t\tE->TE'\n\t\tE'->+TE'|e\n\t\tT->FT'");
    printf("\n\t\tT'->*FT'|e\n\t\tF->(E)|i");
    printf("\nEnter the input expression:");
    scanf("%s", input);
    printf("Expressions");
    printf("\tSequence of production rules\n");
    e();
    // for (i = 0; i < strlen(input); i++)
    // {
    //     if (input[i] != '+' && input[i] != '*' && input[i] != '(' &&
    //         input[i] != ')' && input[i] != 'i' && input[i] != 'I')
    //     {
    //         printf("\nSyntax error");
    //         break;
    //     }
    int k=0;
    for (i = 0; i <= strlen(prod); i++)
        if (prod[i] != 'e')
            temp[k++] = prod[i];
    strcpy(prod, temp);
    printf("E=%-25s", prod);
    
}