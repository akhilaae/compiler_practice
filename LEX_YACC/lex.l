%{
    #include <stdio.h>
    int COMMENT=0,cnt=0;
%}
identifier [a-zA-Z][a-zA-Z0-9]*
%%
#.* {printf("preprocessor\n");};
int|float|double|long|short|char|if|else|do|while|switch|case|default|extern|static|goto|return|break|continue{printf("Keyword\n");};
//* {COMMENT=1;};
/*/ {COMMENT=0; cnt+=1;};
/{ {if(!COMMENT) printf("Block starts");};
/} {if(!COMMENT) printf("Block ends");};
{identifier}/( {if(!COMMENT) printf("Function\n");};
{identifier}(/[[0-9]+/])? {if(!COMMENT) printf("array\n");};
/".*/" {if(!COMMENT) printf("string\n");};
[0-9]* {if(!COMMENT) printf("Number\n");};
/)(/;)? {if(!COMMENT) ECHO; printf("\n");};
/( ECHO;
= {if(!COMMENT) printf("assignment operator\n");};
/<|/>|/>=|/<=|== {if(!COMMENT) printf("relational operator\n");}
/+|/-|/*|//|/% {if(!COMMENT) printf("arithmetic operator\n");}
%%
int main(){
    printf("input : ");
    yyparse();
}
int yyerror(){
    printf("invalid\n");
    exit(0);
}