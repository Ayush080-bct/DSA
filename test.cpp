#include<iostream>
using namespace std;
bool isdigit(char ch)
{
    if(ch - '0'<=9 && int(ch) >=int('0'))
        return true;
    return false;    
}
int main()
{
    if(isdigit('a'))
        cout << "Yes";
    else
        cout << "Nope";
    return 0;        
}