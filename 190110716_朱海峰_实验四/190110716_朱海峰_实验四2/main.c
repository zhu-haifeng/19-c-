#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<math.h>
float TenQuestion()
{
    int a,b,c,ch,s=0,i,j,count=0,answer;
    srand(time(NULL));

    for(i=1;i<=10;i++)
    {
        a=rand()%10;
        b=rand()%10;
        ch=rand()%4;
        c=PrintQuestion(ch,a,b);
        count+=AnswerAndJudge(c);
    }
    printf("Your score this time is %d, and your accuracy is %4f\n",count*10,(float)(count)/10);
    return (float)count/10;

}
int PrintQuestion(int ch,int a,int b)
{

    int c;
    switch (ch)
    {
        case 1:
        {
            c=a+b;
            printf("%d+%d=",a,b);
            break;
        }
        case 2:
        {
            c=a-b;
            printf("%d-%d=",a,b);
            break;
        }
        case 3:
        {
            c=a*b;
            printf("%d*%d=",a,b);
            break;
        }
        case 0:
        {
            c=a/b;
            printf("%d/%d=",a,b);
            break;
        }
    }
    return c;
}
int AnswerAndJudge(int c)
{
    int answer,dh,s;
    dh=rand()%4;
    scanf("%d",&answer);
    if(answer==c)
    {
        switch (dh)
        {
            case 1:
            {
                printf("Very good!\n");
                break;
            }
            case 2:
            {
                printf("Excellent!\n");
                break;
            }
            case 3:
            {
                printf("Nice work!\n");
                break;
            }
            default:
            {
                printf("Keep up the good luck!\n");
            }
        }
    }
    else
    {
        switch (dh)
        {
            case 1:
            {
                printf("No.Please try next subject.\n");
                break;
            }
            case 2:
            {
                printf("Wrong.Becareful.\n");
                break;
            }
            case 3:
            {
                printf("Don't give up!\n");
                break;
            }
            default:
            {
                printf("Not correct.Keep trying.\n");
            }
        }
    }


    return (c==answer)?1:0;
}
int main()
{
    int x;
    while(fabs((TenQuestion()- 0.75)<0))
    {
        printf("\nTry the next time, come on!\n");
    }
}
