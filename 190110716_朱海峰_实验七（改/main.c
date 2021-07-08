#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define N 31
#define Sub 8
/*输入数组*/
void InputRecord(int score[][Sub],int number[],int n,int s,char name[][N])
{
    int i,j;
    printf("please input the scores, numbers and names:\n");
    for(i=0;i<s;i++)
    {
        printf("Sub %d ",i+1);
    }
    printf("number name\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<s;j++)
        {
            scanf("%d",&score[i][j]);
        }
        scanf("%d",&number[i]);
        scanf("%s",&name[i]);
    }
}
/*打印数据*/
void PrintRecord(int score[][Sub],int number[],int n,int s,char name[][N])
{
    int i,j;
    for(i=0;i<s;i++)
    {
        printf("Sub %d ",i+1);
    }
    printf("total average number name\n");
    for(i=0;i<=n+1;i++)
    {
        for(j=0;j<=s+1;j++)
        {
            printf(" %-5d",score[i][j]);
        }
        printf("%6d",number[i]);
        printf("   %s",name[i]);
        printf("\n");
    }
}
/*计算各科总分平均分*/
void CalculateSub(int score[][Sub],int n,int s)
{
    int i,j;
    for(i=0;i<s;i++)
    {
        for(j=0;j<n;j++)
        {
            score[n][i]+=score[j][i];
        }
        score[n+1][i]=score[n][i]/n;
        printf("sub %d total    %d\n",i+1,score[n][i]);
        printf("sub %d average  %d\n",i+1,score[n+1][i]);
    }
}
/*计算各学生总分平均分*/
void CalculateStu(int score[][Sub],int n,int s)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<s;j++)
        {
            score[i][s]+=score[i][j];
        }
        score[i][s+1]=score[i][s]/s;
        printf("stu %d total    %d\n",i+1,score[i][s]);
        printf("stu %d average  %d\n",i+1,score[i][s+1]);
    }
}
/*按分数排序*/
void SelectionSort(int a[][Sub],int b[],int n,int s,int (*compare)(int x,int y),char name[][N])
{
    int i,j,k;
    char t[N];
    for(i=0;i<n;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if((*compare)(a[j][s],a[k][s]))
                k=j;
        }
        if(k!=i)
        {
            for(j=0;j<=s+1;j++)
            {
                Swap(&a[k][j],&a[i][j]);
            }
            Swap(&b[k],&b[i]);
            strcpy(t,name[i]);strcpy(name[i],name[k]);strcpy(name[k],t);
        }
    }
}
/*按学号排序*/
void NumberSort(int a[][Sub],int b[],int n,int s,int (*compare)(int x,int y),char name[][N])
{
    int i,j,k;
    char t[N];
    for(i=0;i<n;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if((compare)(b[j],b[k]))
            {
                k=j;
            }
        }
        if(k!=i)
        {
            for(j=0;j<=s+1;j++)
            {
                Swap(&a[k][j],&a[i][j]);
            }
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
/*按名字排序*/
void NameSort(int a[][Sub],int b[],int n,int s,char name[][N])
{
    int i,j,k;
    char t[N];
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if(strcmp(name[j],name[k])<0)
                k=j;
        }
        if(k!=i)
        {
            for(j=0;j<=s+1;j++)
            {
                Swap(&a[k][j],&a[i][j]);
            }
            Swap(&b[k],&b[i]);
            strcpy(t,name[i]);strcpy(name[i],name[k]);strcpy(name[k],t);
        }
    }
}
/*按学号查找*/
int SearchByNumber(int score[][Sub],int number[],int n,int s,char name[][N])
{
    int i,j,high,low,mid,thescore;
    NumberSort(score,number,n,s,Ascending,name);
    high=n-1;
    low=0;
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
            for(i=0;i<s;i++)
            {
                printf("Sub %d ",i+1);
            }
            printf("total average number name\n");

            for(j=0;j<=s+1;j++)
            {
                printf(" %-5d",score[mid][j]);
            }
            printf("%6d",number[mid]);
            printf("   %s",name[mid]);
            printf("\n");

            thescore=score[mid][s+1];
            break;
        }
    }while(1);
    high=n-1;
    low=0;
    mid=(high+low)/2;
    SelectionSort(score,number,n,s,Descending,name);
    do{
        if(thescore>score[mid][s+1])
        {
            high=mid-1;
            mid=(high+low)/2;;
        }
        else if(score[mid][s+1]>thescore)
        {
            low=mid+1;
            mid=(high+low)/2;
        }
        else
        {
            return mid+1;
            break;
        }
    }while(1);
}
/*按名字查找*/
int SearchByName(int score[][Sub],int number[],int n,int s,char name[][N])
{
    int j,high,low,mid,thescore;
    char i[N];
    NameSort(score,number,n,s,name);
    high=n-1;
    low=0;
    mid=(high+low)/2;
    do{
        printf("please enter the name:\n");
        scanf("%s",i);
    }while(strcmp(i,name[n-1])>0||strcmp(name[0],i)>0);
    do{
        if(strcmp(i,name[mid])<0)
        {
            high=mid-1;
            mid=(high+low)/2;
        }
        else if(strcmp(i,name[mid])>0)
        {
            low=mid+1;
            mid=(high+low)/2;
        }
        else
        {
            for(j=0;j<s;j++)
            {
                printf("Sub %d ",j+1);
            }
            printf("total average number name\n");

            for(j=0;j<=s+1;j++)
            {
                printf(" %-5d",score[mid][j]);
            }
            printf("%6d",number[mid]);
            printf("   %s",name[mid]);
            printf("\n");

            thescore=score[mid][s+1];
            break;
        }
    }while(1);
    high=n-1;
    low=0;
    mid=(high+low)/2;
    SelectionSort(score,number,n,s,Descending,name);
    do{
        if(thescore>score[mid][s+1])
        {
            high=mid-1;
            mid=(high+low)/2;;
        }
        else if(score[mid][s+1]>thescore)
        {
            low=mid+1;
            mid=(high+low)/2;
        }
        else
        {
            return mid+1;
            break;
        }
    }while(1);
}
/*数据分析*/
void StaisticAnalysis(int score[][Sub],int number[],int n,int s)
{
    int i,j,SA[5][Sub]={0};
    char level[5][N]={"excellent","good","medium","pass","fail"};
    for(j=0;j<s;j++)
    {
        for(i=0;i<n;i++)
        {
            if(score[i][j]<=100&&score[i][j]>=90)
            {
                SA[0][j]++;
            }
            else if(score[i][j]<=89&&score[i][j]>=80)
            {
                SA[1][j]++;
            }
            else if(score[i][j]<=79&&score[i][j]>=70)
            {
                SA[2][j]++;
            }
            else if(score[i][j]<=69&&score[i][j]>=60)
            {
                SA[3][j]++;
            }
            else if(score[i][j]<=59&&score[i][j]>=0)
            {
                SA[4][j]++;
            }
        }

    }
    printf("  level   ");
    for(i=0;i<s;i++)
    {
        printf("Sub %d        ",i+1);
    }
    printf("\n");
    for(i=0;i<5;i++)
    {
        printf("%-10s",level[i]);
        for(j=0;j<s;j++)
        {
            printf("%-2d %5.2f%%    ",SA[i][j],100*(float)(SA[i][j])/n);
        }
        printf("\n");
    }
}
int main()
{
    int order,score[N][Sub]={{45,65,98,78,90},{87,98,21,45,98},{98,65,12,45,79},{65,78,98,88,99}},number[N]={5,88,2,6},
    n=4,/*人数*/
    s=5,/*科目数*/
    m/*名次排位*/;
    char name[N][N]={"zhao","qian","sun","li"};
        printf("\n1.Input record\n");
        printf("2.Calculate total and average score of every course\n");
        printf("3.Calculate total and average score of every student\n");
        printf("4.Sort in descending order by total score of every student\n");
        printf("5.Sort in ascending  order by total score of every student\n");
        printf("6.Sort in ascending  order by number\n");
        printf("7.Sort in dictionary order by name\n");
        printf("8.Search by number\n");
        printf("9.Search by name\n");
        printf("10.Statistic analysis for every course\n");
        printf("11.List record\n");
        printf("0.Exit\n\n");
    do{
        printf("Please enter the order:\n");
        scanf("%d",&order);
        if(order==1)
        {
            printf("please input the number of subjects and students:\n");
            scanf("%d%d",&s,&n);
            InputRecord(score,number,n,s,name);
        }
        else if(order==2)
        {
            CalculateSub(score,n,s);
        }
        else if(order==3)
        {
            CalculateStu(score,n,s);
        }
        else if(order==4)
        {
            SelectionSort(score,number,n,s,Descending,name);
            PrintRecord(score,number,n,s,name);
        }
        else if(order==5)
        {
            SelectionSort(score,number,n,s,Ascending,name);
            PrintRecord(score,number,n,s,name);
        }
        else if(order==6)
        {
            NumberSort(score,number,n,s,Ascending,name);
            PrintRecord(score,number,n,s,name);
        }
        else if(order==7)
        {
            NameSort(score,number,n,s,name);
            PrintRecord(score,number,n,s,name);
        }
        else if(order==8)
        {
            m=SearchByNumber(score,number,n,s,name);
            printf("the rank is %d\n",m);
        }
        else if(order==9)
        {
            m=SearchByName(score,number,n,s,name);
            printf("the rank is %d\n",m);
        }
        else if(order==10)
        {
            StaisticAnalysis(score,number,n,s);
        }
        else if(order==11)
        {
            PrintRecord(score,number,n,s,name);
        }
        else if(order!=0)
        {
            printf("wrong input.\n");
        }
    }while(order!=0);
    return 0;
}
