#include<stdio.h>
#include<math.h>
main()
{
    double a,s;
    int i,b[10],count=0;
    do{
        printf("please input an integer:\n");
        scanf("%lf",&s);
    }while(s<=0);

    a=s;
    if(a==1)
    {
        printf("this is not a prime number\n");
        exit(0);
    }

    for(i=2;i<=s/2;i++)
    {
        if(a/i==(int)(a/i))
        {
            a/=i;
            b[count]=i--;
            count++;
        }
    }
    if(count==0)
    {
        printf("this is a prime number\n");
    }
    else
    {
        printf("%d=",(long)s);
        printf("%d",b[0]);
        for(i=1;i<count;i++)
        {
            printf("*%d",b[i]);
        }
    }
    printf("\n");
    return 0;

}
