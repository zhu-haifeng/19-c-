#include<stdio.h>
#include<math.h>
void Judge(double s)
{
    int count=0,i,h=0;
    int static b[10];
    for(i=1;i<=s/2;i++)
    {
        if(s/i==(int)(s/i))
        {
            b[count]=i;
            count++;
        }
    }
    for(i=0;i<=count-1;i++)
    {
        h+=b[i];
    }
    if (s==h)
    {
        printf("%d is a perfect number.\n",(long)s);
    }
    else
    {
        printf("%d is not a perfect number.\n",(long)s);
    }


}

main()
{
    double a,s;
    int j;
    do{
        printf("please input an integer:\n");
        scanf("%ld",&j);
    }while(j<=0);
    Judge(j);


}
