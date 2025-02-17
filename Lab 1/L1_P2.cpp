#include<stdio.h>
int main(){
    double a,n=0,avg;
    int i;
    double array[10];
    double *ptr=array;
    for(i=0;i<10;i++){
        scanf("%lf",(ptr+i));
        n=n+*(ptr+i);

    }
    avg=n/10;
    printf("avg: %lf",avg);

    return 0;
}
