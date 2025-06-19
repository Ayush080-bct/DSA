#include<stdio.h>

long int tailfact(int n,int a)
{
    if(n==0)
        return a;
    else
        return tailfact(n-1,n*a);
    
}
int main()
{
    int a=1;
    int result=tailfact(5,a);
    printf("%ld",result);
    return 0;
}