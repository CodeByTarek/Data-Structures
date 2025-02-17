#include<stdio.h>
void copystr(char *dest, char *src){
    int i=0;
    while(*src!='\0'){
        *dest++ = *src++;

}
int main(){
    char source[] = "Hello World!";
    char destination[100];
    copystr(destination,source);
    printf("%s",destination);

    return 0;

}

