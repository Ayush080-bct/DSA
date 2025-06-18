//stable sort
//inplace
//adaptive
#include<stdio.h>

void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void Bubblesort(int a[],int n)

{
    int temp,i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(&a[j],&a[j+1]);
                
            }
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
    printf("Enter the number of Elements: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    Bubblesort(a,n);

    return 0;

}