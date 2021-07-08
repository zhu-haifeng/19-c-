#include <stdio.h>
#include <stdlib.h>
#define N 31
/*输入数组*/
int InputRecord(int score[],int number[])
{
    int i;
    printf("please input the scores and numbers:\n");
    for(i=1;i<=30;i++)
    {
        scanf("%d%d",&score[i],&number[i]);             /*输入负数来结束录入*/
        if(score[i]<=0||&number[i]<0)
            break;
    }
    return i-1;
}
/*打印数据*/
void PrintRecord(int score[],int number[],int n)
{
    int i;
    printf("score     number\n");
    for(i=1;i<=n;i++)
    {
        printf("%-10d %-10d\n",score[i],number[i]);
    }
}
/*计算总数平均数*/
void Calculate(int score[],int n)
{
    int i,sum=0,ave;
    for(i=1;i<=n;i++)
    {
        sum+=score[i];
    }
    ave=sum/n;
    printf("the total score is %d\n",sum);
    printf("the average score is %d\n",ave);
}
/*按分数排序*/
void SelectionSort(int a[],int b[],int n,int (*compare)(int a,int b))
{
    int i,j,k;
    for(i=1;i<=n-1;i++)
    {
        k=i;
        for(j=i+1;j<=n;j++)
        {
            if((*compare)(a[j],a[k]))
                k=j;
        }
        if(k!=i)
        {
            Swap(&a[k],&a[i]);
            Swap(&b[k],&b[i]);
        }
    }
}
/*按学号排序*/
void NumberSort(int a[],int b[],int n,int (*compare)(int a,int b))
{
    int i,j,k;
    for(i=1;i<=n-1;i++)
    {
        k=i;
        for(j=i+1;j<=n;j++)
        {
            if((*compare)(b[j],b[k]))
                k=j;
        }
        if(k!=i)
        {
            Swap(&a[k],&a[i]);
            Swap(&b[k],&b[i]);
        }
    }
}
int Ascending(int a,int b)
{
    return a<b;
}
int Descending(int a,int b)
{
    return a>b;
}
/*交换两个数*/
void Swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
/*按学号查找*/
void SearchByNumber(int score[],int number[],int n)
{
    int i,high,low,mid;
    NumberSort(score,number,n,Ascending);
    high=n;
    low=1;
    mid=(high+low)/2;
    do{
        printf("please enter the number:\n");
        scanf("%d",&i);
    }while(i>number[high]||i<number[low]);

    do{
        if(i<number[mid])
        {
            high=mid-1;
            mid=(high+low)/2;;
        }
        else if(number[mid]<i)
        {
            low=mid+1;
            mid=(high+low)/2;
        }
        else
        {
            printf("%d %d\n",score[mid],number[mid]);
            break;
        }

    }while(1);
}
/*数据分析*/
void StaisticAnalysis(int score[],int number[],int n)
{
    int i,excellent=0,good=0,medium=0,pass=0,fail=0;
    for(i=1;i<=n;i++)
    {
        if(score[i]<=100&&score[i]>=90)
        {
            excellent++;
        }
        else if(score[i]<=89&&score[i]>=80)
        {
            good++;
        }
        else if(score[i]<=79&&score[i]>=70)
        {
            medium++;
        }
        else if(score[i]<=69&&score[i]>=60)
        {
            pass++;
        }
        else if(score[i]<=59&&score[i]>=0)
        {
            fail++;
        }
    }
    printf("the excellent level is %d, the rate is %.4f\n",excellent,(float)(excellent)/n);
    printf("the   good    level is %d, the rate is %.4f\n",good,(float)(good)/n);
    printf("the  medium   level is %d, the rate is %.4f\n",medium,(float)(medium)/n);
    printf("the   pass    level is %d, the rate is %.4f\n",pass,(float)(pass)/n);
    printf("the   fail    level is %d, the rate is %.4f\n",fail,(float)(fail)/n);
}
int main()
{
    int order,score[N]={0},number[N]={0},n;
        printf("\n\n1.Input record\n");
        printf("2.Calculate total and average score of course\n");
        printf("3.Sort in descending order by score\n");
        printf("4.Sort in ascending  order by score\n");
        printf("5.Sort in ascending  order by number\n");
        printf("6.Search by number\n");
        printf("7.Statistic analysis\n");
        printf("8.List record\n");
        printf("0.Exit\n");
    do{
        printf("Please enter the order:\n");
        scanf("%d",&order);
        if(order==1)
        {
            n=InputRecord(score,number);
        }
        else if(order==2)
        {
            Calculate(score,n);
        }
        else if(order==3)
        {
            SelectionSort(score,number,n,Descending);
            PrintRecord(score,number,n);
        }
        else if(order==4)
        {
            SelectionSort(score,number,n,Ascending);
            PrintRecord(score,number,n);
        }
        else if(order==5)
        {
            NumberSort(score,number,n,Ascending);
            PrintRecord(score,number,n);
        }
        else if(order==6)
        {
            SearchByNumber(score,number,n);
        }
        else if(order==7)
        {
            StaisticAnalysis(score,number,n);
        }
        else if(order==8)
        {
            PrintRecord(score,number,n);
        }
        else if(order!=0)
        {
            printf("wrong input.\n");
        }
    }while(order!=0);
    return 0;
}
