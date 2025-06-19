#include"Myfloor_func.h"
#include<stdio.h>

void merge(int a[],int l,int m,int r)
{
    int i,j,k;
    int b[100];
    i=l;j=m+1;k=l;
    while(i<=m && j<=r){
        if(a[i]<a[j])
        {
            b[k++]=a[i++];
        }
        else{
            b[k++]=a[j++];
        }
    }
    for(;i<=m;i++,k++)/*same like while(i<=m)
    b[k++]=a[i++]*/
    {
        b[k]=a[i];
    }
    for(;j<=r;j++,k++)
    {
        b[k]=a[j];
    }
    for(i=l;i<=r;i++)
    {
        a[i]=b[i];
    }

}
void mergesort(int a[],int l,int r){
    if(l<r){
        int m=myfloor((l+r)/2.0f);
       
        
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
    }

}