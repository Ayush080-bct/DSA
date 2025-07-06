//stable sort
//inplace
//adaptive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void selectionsort(int a[],int n)

{
    int i,j;
    for(i=0;i<n;i++)
    {
        int least=a[i];
        int pos=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<least)
            {
                least=a[j];
                pos=j;
                
            }
        }
        if(i!=pos){
            swap(&a[i],&a[pos]);
        }
    }
    printf("Sorted oreder : ");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
     
    }
}
int main()
{
    int n,a[100];
    time_t start=time(NULL);
    printf("Enter the number of Elements: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(int i=0;i<n;i++)
    {
        a[i]=rand()%10;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d",a[i]);
        printf("\t");
    }
    printf("\n");
     




    

    
    selectionsort(a,n);
    printf("\n");
    time_t end=time(NULL);
int second=difftime(end,start);
printf("The time taken is %d",second);


    return 0;

}