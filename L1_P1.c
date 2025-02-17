#include<stdio.h>
int main()
{
    int a, b;
    int *pa=&a, *pb=&b;
    scanf("%d %d", &a,&b);
    update(pa,pb);
    printf("%d\n%d",a,b);
    return 0;
}
void update(int *a,int *b){
    int c,d;
    c=*a+*b;
    d=*a-*b;
    d=sqrt(d*d);
    *a=c;
    *b=d;
    printf("Sum: %d\n",c);
    printf("Difference: %d\n",d);

}
