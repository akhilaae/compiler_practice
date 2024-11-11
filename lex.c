#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
char input[30];
int left,right,len;
bool isDelimiter(char str){
    if (str==' '||str=='+'||str=='-'||str=='*'||str=='/'||str=='%'||str==';'||str=='.'||str=='('||str==')'||str=='['||str==']'||str=='{'||str=='}'||str==','||str=='='||str=='<'||str=='>'){
        return true;
    }
    return false;
}
bool isOperator(char str){
    if (str=='+'||str=='-'||str=='*'||str=='/'||str=='%'||str=='='||str=='<'||str=='>'){
        return true;
    }
    return false;
}
bool isKeyword(char* str){
    if(str=="if"||str=="else"||str=="for"||str=="do"||str=="while"||str=="int"||str=="char"||str=="float"||str=="double"||str=="main"||str=="break"||str=="continue"||str=="pass"||str=="sizeof"||str=="return"||str=="case"||str=="switch"||str=="long"||str=="short"||str=="typedef"||str=="struct"||str=="unsigned"||str=="void"||str=="static"||str=="extern"){
        return true;
    }
    return false;
}
bool isInteger(char* str){
    if(len==0) return false;
    for(int i=0;i<len;i++){
        if (str[i]!='0'&& str[i]!='1'&& str[i]!='2'&& str[i]!='3'&& str[i]!='4'&& str[i]!='5'&& str[i]!='6'&& str[i]!='7'&& str[i]!='8'&& str[i]!='9'){
            return false;
        }
    }
    return true;
}
bool isRealNumber(char* str){
    bool hasDecimal=false;
    if(len==0) return false;
    for(int i=0;i<len;i++){
        if (str[i]!='0'&& str[i]!='1'&& str[i]!='2'&& str[i]!='3'&& str[i]!='4'&& str[i]!='5'&& str[i]!='6'&& str[i]!='7'&& str[i]!='8'&& str[i]!='9' && str[i]!='.' || (str[i]=='-' && i>0)){
            return false;
        }
        if(str[i]=='.'){
            if (hasDecimal==true) return false;
            hasDecimal=true;
        }
    }
    return hasDecimal;
}
bool isValidIdentifier(char* str){
    if(str[0]=='0'||str[0]=='1'||str[0]=='2'||str[0]=='3'||str[0]=='4'||str[0]=='5'||str[0]=='6'||str[0]=='7'||str[0]=='8'||str[0]=='9'||str[0]=='_'){
        return false;
    }
    return true;
}
char* subStr(char* str, int right, int left){
    char* sub=(char*)malloc(sizeof(char)*(right-left+2));
    for(int i=left;i<=right;++i){
        sub[i-left]=str[i];
    }
    sub[right-left+1]='\0';
    return sub;
}
void parse(char* str){
    left=0,right=0,len=strlen(str);
    while (right<len && left<=right){
        if (isDelimiter(str[right])==false){
            right++;
        }
        if (isDelimiter(str[right])==true && left==right){
            if (isOperator(str[right])==true){
                printf("%c is an operator\n",str[right]);
                right++;
                left=right;
            }
        }
        if (isDelimiter(str[right])==true && left!=right || left!=right && right==len){
            char* substr=subStr(str,right,left);
            if (isKeyword(substr)){
                printf("Keyword!\n");
            }
            else if(isInteger(substr)){
                printf("Integer\n");
            }
            else if(isRealNumber(substr)){
                printf("Real no\n");
            }
            else if(isValidIdentifier(substr) && isDelimiter(str[right - 1]) == false){
                printf("Identifier\n");
            }
            else if(!isValidIdentifier(substr) && isDelimiter(str[right - 1]) == false){
                printf("Not Valid Identifier\n");
            }
        left=right;
        }
    }
}
void main(){
    printf("Enter input : ");
    scanf("%s",input);
    parse(input);
}