#include<stdio.h>
int main(){
    double a;
    int i;
    double array[10];
    double *ptr=array;
    for(i=0;i<10;i++){
        scanf("%lf",&ptr+i);
        printf("%lf",(*ptr+i));
    }

    return 0;
}
