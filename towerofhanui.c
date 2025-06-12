#include<stdio.h>
void toh(int n,char src,char dst,char tmp)
{
    if(n==1){
        printf("Move the disc %d from %c to %c\n",n,src,dst);
    }
    else{
        toh(n-1,src,tmp,dst);
        printf("Move the disc %d from %c to %c\n",n,src,dst);
        toh(n-1,tmp,dst,src);
    }
}
int main()
{
    int n;
    
    printf("Enter the number of disc: ");
    scanf("%d",&n);
    toh(n,'a','b','c');
    return 0;
}