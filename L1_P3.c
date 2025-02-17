#include<stdio.h>
#include<math.h>
int main(){
    int i;
    double array1[] = {1,2,3,4,5};
    double array2[] = {6,7,8,9,10};
    double array3[5];
    double *ptrArray1 = array1;
    double *ptrArray2 = array2;
    double *ptrArray3 = array3;
    addarrays(ptrArray1,ptrArray2,ptrArray3);
    for(i=0;i<5;i++){
        printf("%lf\n",*(array3+i));
    }


}
void addarrays(double *a,double *b,double *c){
    int i;
    for(i=0;i<5;i++){
        *(c+i) = *(a+i)+*(b+i);
    }

    }
