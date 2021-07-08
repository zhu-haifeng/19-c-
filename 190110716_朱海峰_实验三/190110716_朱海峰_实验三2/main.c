#include <stdio.h>
#include <stdlib.h>

int main()
{
    long double a=1,s=0,v=0;
    int i;
    for(i=1;i<=64;i++)
    {
        s+=a;
        a*=2;
    }
    v=s/1.42e8;
    printf("v=%lf",v);
    return 0;
}
