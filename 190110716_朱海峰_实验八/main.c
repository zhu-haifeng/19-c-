#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define N 31
#define Sub 8
typedef struct student
{
    long studentID;
    char studentName[N];
    int score[Sub];
}STUDENT;
/*输入数组*/
void InputRecord(STUDENT stu[],int n,int s)
{
    int i,j;
    printf("please input the studentID, name and scores:\n");
    printf("ID  name   ");
    for(i=0;i<s;i++)
    {
        printf("Sub %d ",i+1);
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        scanf("%ld%s",&stu[i].studentID,stu[i].studentName);
        for(j=0;j<s;j++)
        {
            scanf("%d",&stu[i].score[j]);
        }
    }
}
/*打印数据*/
void PrintRecord(STUDENT stu[],int n,int s)
{
    int i,j;
    printf("  ID     name   ");
    for(i=0;i<s;i++)
    {
        printf("Sub %d ",i+1);
    }
    printf("total average\n");
    for(i=0;i<=n+1;i++)
    {
        printf("%5ld %7s",stu[i].studentID,stu[i].studentName);
        for(j=0;j<=s+1;j++)
        {
            printf("  %4d",stu[i].score[j]);
        }
        printf("\n");
    }
}
/*计算各科总分平均分*/
void CalculateSub(STUDENT stu[],int n,int s)
{
    int i,j;
    for(i=0;i<s;i++)
    {
        for(j=0;j<n;j++)
        {
            stu[n].score[i]+=stu[j].score[i];
        }
        stu[n+1].score[i]=stu[n].score[i]/n;
        printf("sub %d total    %d\n",i+1,stu[n].score[i]);
        printf("sub %d average  %d\n",i+1,stu[n+1].score[i]);
    }
}
/*计算各学生总分平均分*/
void CalculateStu(STUDENT stu[],int n,int s)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<s;j++)
        {
            stu[i].score[s]+=stu[i].score[j];
        }
        stu[i].score[s+1]=stu[i].score[s]/s;
        printf("stu %d total    %d\n",i+1,stu[i].score[s]);
        printf("stu %d average  %d\n",i+1,stu[i].score[s+1]);
    }
}
void SelectionSort(STUDENT stu[],int n,int s,int (*compare)(int x,int y))
{
    int i,j,k;
    STUDENT temp;
    for(i=0;i<n;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if((*compare)(stu[j].score[s],stu[k].score[s]))
                k=j;
        }
        if(k!=i)
        {
            temp=stu[i];
            stu[i]=stu[k];
            stu[k]=temp;
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
/*按学号排序*/
void NumberSort(STUDENT stu[],int n,int s)
{
    int i,j,k;
    STUDENT temp;
    for(i=0;i<n;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if((stu[j].studentID<stu[k].studentID))
                k=j;
        }
        if(k!=i)
        {
            temp=stu[i];
            stu[i]=stu[k];
            stu[k]=temp;
        }
    }
}
/*按名字排序*/
void NameSort(STUDENT stu[],int n,int s)
{
    int i,j,k;
    STUDENT temp;
    for(i=0;i<n;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if(strcmp(stu[j].studentName,stu[k].studentName)<0)
                k=j;
        }
        if(k!=i)
        {
            temp=stu[i];
            stu[i]=stu[k];
            stu[k]=temp;
        }
    }
}
/*按学号查找*/
int SearchByNumber(STUDENT stu[],int n,int s)
{
    int i,j,high,low,mid,thescore;
    NumberSort(stu,n,s);
    high=n-1;
    low=0;
    mid=(high+low)/2;
    do{
        printf("please enter the number:\n");
        scanf("%d",&i);
    }while(i>stu[high].studentID||i<stu[low].studentID);

    do{
        if(i<stu[mid].studentID)
        {
            high=mid-1;
            mid=(high+low)/2;;
        }
        else if(stu[mid].studentID<i)
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
                printf(" %-5d",stu[mid].score[j]);
            }
            printf("%6d",stu[mid].studentID);
            printf("   %s",stu[mid].studentName);
            printf("\n");

            thescore=stu[mid].score[s+1];
            break;
        }
    }while(1);
    high=n-1;
    low=0;
    mid=(high+low)/2;
    SelectionSort(stu,n,s,Descending);
    do{
        if(thescore>stu[mid].score[s+1])
        {
            high=mid-1;
            mid=(high+low)/2;;
        }
        else if(stu[mid].score[s+1]>thescore)
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
int SearchByName(STUDENT stu[],int n,int s)
{
    int j,high,low,mid,thescore;
    char i[N];
    NameSort(stu,n,s);
    high=n-1;
    low=0;
    mid=(high+low)/2;
    do{
        printf("please enter the name:\n");
        scanf("%s",i);
    }while(strcmp(i,stu[n-1].studentName)>0||strcmp(stu[0].studentName,i)>0);
    do{
        if(strcmp(i,stu[mid].studentName)<0)
        {
            high=mid-1;
            mid=(high+low)/2;
        }
        else if(strcmp(i,stu[mid].studentName)>0)
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
                printf(" %-5d",stu[mid].score[j]);
            }
            printf("%6d",stu[mid].studentID);
            printf("   %s",stu[mid].studentName);
            printf("\n");

            thescore=stu[mid].score[s+1];
            break;
        }
    }while(1);
    high=n-1;
    low=0;
    mid=(high+low)/2;
    SelectionSort(stu,n,s,Descending);
    do{
        if(thescore>stu[mid].score[s+1])
        {
            high=mid-1;
            mid=(high+low)/2;
        }
        else if(stu[mid].score[s+1]>thescore)
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
void StaisticAnalysis(STUDENT stu[],int n,int s)
{
    int i,j,SA[5][Sub]={0};
    char level[5][N]={"excellent","good","medium","pass","fail"};
    for(j=0;j<s;j++)
    {
        for(i=0;i<n;i++)
        {
            if(stu[i].score[j]<=100&&stu[i].score[j]>=90)
            {
                SA[0][j]++;
            }
            else if(stu[i].score[j]<=89&&stu[i].score[j]>=80)
            {
                SA[1][j]++;
            }
            else if(stu[i].score[j]<=79&&stu[i].score[j]>=70)
            {
                SA[2][j]++;
            }
            else if(stu[i].score[j]<=69&&stu[i].score[j]>=60)
            {
                SA[3][j]++;
            }
            else if(stu[i].score[j]<=59&&stu[i].score[j]>=0)
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
    STUDENT stu[N]={
                    {11,"zhao",{45,65,98,78,90}       },
                    {2,"qian",{87,98,21,45,98}        },
                    {5,"sun",{98,65,12,45,79}         },
                    {45,"li",{65,78,98,88,99}         },
                    };
    int order,n=4,/*人数*/
    s=5,/*科目数*/
    m/*名次排位*/;
    stu[n].studentName[N]="total";
    stu[n+1].studentName[N]="average";
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
            InputRecord(stu,n,s);
            stu[n].studentName[N]="total";
            stu[n+1].studentName[N]="average";
        }
        else if(order==2)
        {
            CalculateSub(stu,n,s);
        }
        else if(order==3)
        {
            CalculateStu(stu,n,s);
        }
        else if(order==4)
        {
            SelectionSort(stu,n,s,Descending);
            PrintRecord(stu,n,s);
        }
        else if(order==5)
        {
            SelectionSort(stu,n,s,Ascending);
            PrintRecord(stu,n,s);
        }
        else if(order==6)
        {
            NumberSort(stu,n,s);
            PrintRecord(stu,n,s);
        }
        else if(order==7)
        {
            NameSort(stu,n,s);
            PrintRecord(stu,n,s);
        }
        else if(order==8)
        {
            m=SearchByNumber(stu,n,s);
            printf("the rank is %d\n",m);
        }
        else if(order==9)
        {
            m=SearchByName(stu,n,s);
            printf("the rank is %d\n",m);
        }
        else if(order==10)
        {
            StaisticAnalysis(stu,n,s);
        }
        else if(order==11)
        {
            PrintRecord(stu,n,s);
        }
        else if(order!=0)
        {
            printf("wrong input.\n");
        }
    }while(order!=0);
    return 0;
}
