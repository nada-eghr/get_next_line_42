#include <stdio.h>

void fun()
{ 
    static int a = 5 ;
    int b = 2;
    a = a + b;
    printf("%d\n",a);
}
int main()
{
   
    fun();
    fun();
    fun();
}