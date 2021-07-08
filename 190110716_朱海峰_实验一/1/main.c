#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Number: 190110716\nsubject number 1  date 9.25\n\n");
    int a;
    short b;
    char c;
    long d;
    double f;
    float e;

    printf("input an int:");
    scanf("%d",&a);
    printf("int a=%d, size of int=%d\n",a,sizeof(int));

    printf("input a short:");
    scanf("%d",&b);
    printf("short c=%hd, size of short=%d\n",b,sizeof(short));

    printf("input a char:");
    scanf("%c",&c);
    printf("int c=%c, size of char=%d\n",c,sizeof(char));

    printf("input a long:");
    scanf("%ld",&d);
    printf("int d=%ld, size of long=%ld\n",d,sizeof(long));

    printf("input a float:");
    scanf("%f",&e);
    printf("int e=%f, size of float=%d\n",e,sizeof(float));

    printf("input a double:");
    scanf("%lf",&f);
    printf("int f=%f, size of double=%d\n",f,sizeof(double));


}
