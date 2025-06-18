#include"Myfloor_func.h"
int myfloor(float x)
{
    int a=(int)x;
    return(x>=0 || a==x)?a :a-1;
}