#include<stdio.h>
long int gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        return(b,a%b);
    }
}
int main()
{
    int result=gcd(18,12);
    print("HCF : %d",result);
}

