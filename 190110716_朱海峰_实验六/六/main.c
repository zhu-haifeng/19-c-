#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define N 31
/*输入数组*/
int InputRecord(int score[],int number[],char name[][N])
{
    int i;
    printf("please input the scores, numbers and names:\n");
    for(i=1;i<=30;i++)
    {
        scanf("%d%d%s",&score[i],&number[i],name[i]);             /*输入负数来结束录入*/
        if(score[i]<=0||&number[i]<0)
            break;
    }
    return i-1;
}
/*打印数据*/
void PrintRecord(int score[],int number[],int n,char name[][N])
{
    int i;
    printf("score     number         name\n");
    for(i=1;i<=n;i++)
    {
        printf("%-10d %-10d  %s\n",score[i],number[i],name[i]);
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
void SelectionSort(int a[],int b[],int n,int (*compare)(int x,int y),char name[][N])
{
    int i,j,k;
    char t[N];
    for(i=1;i<n;i++)
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
            strcpy(t,name[i]);strcpy(name[i],name[k]);strcpy(name[k],t);
        }
    }
}
/*按学号排序*/
void NumberSort(int a[],int b[],int n,int (*compare)(int x,int y),char name[][N])
{
    int i,j,k;
    char t[N];
    for(i=1;i<n;i++)
    {
        k=i;
        for(j=i+1;j<=n;j++)
        {
            if((compare)(b[j],b[k]))
            {
                k=j;
            }
        }
        if(k!=i)
        {
            Swap(&a[k],&a[i]);
            Swap(&b[k],&b[i]);
            strcpy(t,name[i]);strcpy(name[i],name[k]);strcpy(name[k],t);
        }
    }
}
/*按名字排序*/
void NameSort(int a[],int b[],int n,char name[][N])
{
    int i,j,k;
    char t[N];
    for(i=1;i<=n-1;i++)
    {
        k=i;
        for(j=i+1;j<=n;j++)
        {
            if(strcmp(name[j],name[k])<0)
                k=j;
        }
        if(k!=i)
        {
            Swap(&a[k],&a[i]);
            Swap(&b[k],&b[i]);
            strcpy(t,name[i]);strcpy(name[i],name[k]);strcpy(name[k],t);
        }
    }
}
int Ascending(int x,int y)
{
    return x<y;
}
int Descending(int x,int y)
{
    return x>y;
}
/*交换两个数*/
void Swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
/*按学号查找*/
int SearchByNumber(int score[],int number[],int n,char name[][N])
{
    int i,high,low,mid,thescore;
    NumberSort(score,number,n,Ascending,name);
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
            printf("score:%d number:%d name:%s\n",score[mid],number[mid],name[mid]);
            thescore=score[mid];
            break;
        }
    }while(1);
    high=n;
    low=1;
    mid=(high+low)/2;
    SelectionSort(score,number,n,Descending,name);
    do{
        if(thescore>score[mid])
        {
            high=mid-1;
            mid=(high+low)/2;;
        }
        else if(score[mid]>thescore)
        {
            low=mid+1;
            mid=(high+low)/2;
        }
        else
        {
            return mid;
            break;
        }
    }while(1);
}
/*按名字查找*/
int SearchByName(int score[],int number[],int n,char name[][N])
{
    int high,low,mid,thescore;
    char i[N];
    NameSort(score,number,n,name);
    high=n;
    low=1;
    mid=(high+low)/2;
    do{
        printf("please enter the name:\n");
        scanf("%s",i);
    }while(strcmp(i,name[n])>0||strcmp(name[1],i)>0);

    do{
        if(strcmp(i,name[mid])<0)
        {
            high=mid-1;
            mid=(high+low)/2;;
        }
        else if(strcmp(i,name[mid])>0)
        {
            low=mid+1;
            mid=(high+low)/2;
        }
        else
        {
            printf("score:%d number:%d name:%s\n",score[mid],number[mid],name[mid]);
            thescore=score[mid];
            break;
        }
    }while(1);
    high=n;
    low=1;
    mid=(high+low)/2;
    SelectionSort(score,number,n,Descending,name);
    do{
        if(thescore>score[mid])
        {
            high=mid-1;
            mid=(high+low)/2;;
        }
        else if(score[mid]>thescore)
        {
            low=mid+1;
            mid=(high+low)/2;
        }
        else
        {
            return mid;
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
    printf("the excellent level is %d, the rate is %.2f%\n",excellent,100*(float)(excellent)/n);
    printf("the   good    level is %d, the rate is %.2f%\n",good,100*(float)(good)/n);
    printf("the  medium   level is %d, the rate is %.2f%\n",medium,100*(float)(medium)/n);
    printf("the   pass    level is %d, the rate is %.2f%\n",pass,100*(float)(pass)/n);
    printf("the   fail    level is %d, the rate is %.2f%\n",fail,100*(float)(fail)/n);
}
int main()
{
    int order,score[N]={0},number[N]={0},n=9,m/*名次排位*/;
    char name[N][N];
        printf("\n1.Input record\n");
        printf("2.Calculate total and average score of course\n");
        printf("3.Sort in descending order by score\n");
        printf("4.Sort in ascending  order by score\n");
        printf("5.Sort in ascending  order by number\n");
        printf("6.Sort in dictionary order by name\n");
        printf("7.Search by number\n");
        printf("8.Search by name\n");
        printf("9.Statistic analysis\n");
        printf("10.List record\n");
        printf("0.Exit\n\n");
    do{
        printf("Please enter the order:\n");
        scanf("%d",&order);
        if(order==1)
        {
            n=InputRecord(score,number,name);
        }
        else if(order==2)
        {
            Calculate(score,n);
        }
        else if(order==3)
        {
            SelectionSort(score,number,n,Descending,name);
            PrintRecord(score,number,n,name);
        }
        else if(order==4)
        {
            SelectionSort(score,number,n,Ascending,name);
            PrintRecord(score,number,n,name);
        }
        else if(order==5)
        {
            NumberSort(score,number,n,Ascending,name);
            PrintRecord(score,number,n,name);
        }
        else if(order==6)
        {
            NameSort(score,number,n,name);
            PrintRecord(score,number,n,name);
        }
        else if(order==7)
        {
            m=SearchByNumber(score,number,n,name);
            printf("the ranking is %d\n",m);
        }
        else if(order==8)
        {
            m=SearchByName(score,number,n,name);
            printf("the ranking is %d\n",m);
        }
        else if(order==9)
        {
            StaisticAnalysis(score,number,n);
        }
        else if(order==10)
        {
            PrintRecord(score,number,n,name);
            Calculate(score,n);
        }
        else if(order!=0)
        {
            printf("wrong input.\n");
        }
    }while(order!=0);
    return 0;
}
