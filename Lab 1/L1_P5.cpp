//Md. Ashikur Rahman
#include<stdio.h>
#include<string.h>
#include<ctype.h>
void upit(char* str){
    int i=0;
    //printf("%s\n",toupper(*str));

    //strupr(*str);
    //*str=toupper(*(str));
    while(*str!='\0'){
            *(str)=toupper(*(str));
            *str++;
            i++;
        }
        i=i+1;

        *(str+i)='\0';

}
int main(){
    printf("\n");
    char src[] = "life is good";
    upit(src);
    printf("%s\n",src);
    return 0;

}

