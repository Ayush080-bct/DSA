#include<stdio.h>
#include<time.h>

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
    time_t start, end;
    double seconds;

    start=time(NULL);
    printf("Enter the number of disc: ");
    scanf("%d",&n);
    toh(n,'a','c','b');
    end=time(NULL);
    seconds=difftime(end,start);
    printf("The time taken to complete is: %f",seconds);
    return 0;
}