#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<math.h>
int AnsweAndJudge(int a,int b)
{
    int i,j,c,answer,score=0;
    c=a*b;
    for(j=1;j<=3;j++)
    {
        scanf("%d",&answer);
        if(answer==c)
        {
            printf("Right!\n\n");
            score=10;
            break;
        }
        else if(j!=3)
        {
            printf("Wrong!Please try again!\n");
        }
        else
        {
            printf("Wrong!Test next subject!\n\n");
        }
    }
    return score;
}
int main()
{
    int a,b,s=0,i,j,answer;
    srand(time(NULL));

    for(i=1;i<=10;i++)
    {
        a=rand()%10;
        b=rand()%10;

        printf("%d*%d=",a,b);

        s+=AnsweAndJudge(a,b);
    }
    printf("Your score is %d, and your accuracy is %f\n",s,(float)(s)/100);
    return 0;
}
