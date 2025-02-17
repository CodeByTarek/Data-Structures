#include<stdio.h>
void copyString(char *src, char *dest){
        int i=0;

        while(*src!='\0'){
            *(dest+i)=*(src+i);
            i++;
        }
        i=i+1;

        *(dest+i)='\0';
    }
int main(){
    printf("\n");
    char source[]="Hello World!";
    char destination[100];
    copyString(source,destination);
    printf("%s\n",destination);


    return 0;
}

