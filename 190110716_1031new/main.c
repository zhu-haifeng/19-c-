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
/*输入数据*/
void InputRecord(STUDENT stu[],int n,int s)
{
    int i,j,error;
    printf("please input the studentID, name and scores:\n");
    printf("      ID       name  ");
    for(i=0;i<s;i++)
    {
        printf("  Sub %d",i+1);
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        do{
                error=0;
                printf("stu%d:",i+1);
                scanf("%ld%s",&stu[i].studentID,stu[i].studentName);
                for(j=0;j<s;j++)
                {
                    scanf("%d",&stu[i].score[j]);
                    if(stu[i].score[j]>100||stu[i].score[j]<0)
                    {
                        error=1;
                    }
                }
                if(error==1)
                {
                    printf("wrong input!,please enter again:\n");
                }
            }while(error==1);
    }
}
/*打印数据*/
void PrintRecord(STUDENT stu[],int n,int s)
{
    int i,j;
    printf("  ID       name   ");
    for(i=0;i<s;i++)
    {
        printf("Sub %d ",i+1);
    }
    printf("total average\n");
    for(i=0;i<=n+1;i++)
    {
        printf("%7ld %7s",stu[i].studentID,stu[i].studentName);
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
    for(i=0;i<s+2;i++)
    {
        stu[n].score[i]=stu[n+1].score[i]=0;
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
    for(i=0;i<n+2;i++)
    {
        stu[i].score[s]=stu[i].score[s+1]=0;
        for(j=0;j<s;j++)
        {
            stu[i].score[s]+=stu[i].score[j];
        }
        stu[i].score[s+1]=stu[i].score[s]/s;
        printf("stu %d total    %d\n",i+1,stu[i].score[s]);
        printf("stu %d average  %d\n",i+1,stu[i].score[s+1]);
    }
}
/*按分数升序/降序排序*/
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
    int i,j,high,low,mid,thescore,
        find=0;
    NumberSort(stu,n,s);
    high=n-1;
    low=0;
    mid=(high+low)/2;
    do{
        high=n-1;
        low=0;
        mid=(high+low)/2;
        printf("please enter the number:\n");
        scanf("%d",&i);
        do{
            if((i<stu[mid].studentID)&&high>low)
            {
                high=mid-1;
                mid=(high+low)/2;
            }
            else if(i>stu[mid].studentID&&high>low)
            {
                low=mid+1;
                mid=(high+low)/2;
            }
            else if(i!=stu[mid].studentID)
            {
                printf("there is not a number as input!\n");
                break;
            }
            else
            {
                for(j=0;j<s;j++)
                {
                    printf("Sub %d ",j+1);
                }
                printf("total average ID name\n");
                find=1;
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
    }while(i>stu[n-1].studentID||i<stu[0].studentID||find==0);
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
    int j,high,low,mid,thescore,
        find=0;
    char i[N];
    NameSort(stu,n,s);

    do{
        high=n-1;
        low=0;
        mid=(high+low)/2;
        printf("please enter the name:\n");
        scanf("%s",i);
        do{
            if(strcmp(i,stu[mid].studentName)<0&&high>low)
            {
                high=mid-1;
                mid=(high+low)/2;
            }
            else if(strcmp(i,stu[mid].studentName)>0&&high>low)
            {
                low=mid+1;
                mid=(high+low)/2;
            }
            else if(strcmp(i,stu[mid].studentName)!=0)
            {
                printf("there is not a name as input!\n");
                break;
            }
            else
            {
                for(j=0;j<s;j++)
                {
                    printf("Sub %d ",j+1);
                }
                printf("total average number name\n");
                find=1;
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
    }while(strcmp(i,stu[n-1].studentName)>0||strcmp(stu[0].studentName,i)>0||find==0);

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
/*写入文件 */
void WritetoFile(STUDENT stu[],int n,int s)
{
    FILE *fp;
    int i,j;
    if((fp=fopen("student.txt","w"))==NULL)
    {
        printf("Failure to open student.txt!\n");
        exit(1);
    }
    fprintf(fp,"%d\t%d\n",n,s);
    for(i=0;i<n+2;i++)
    {
        fprintf(fp,"%7ld %7s",stu[i].studentID,stu[i].studentName);
        for(j=0;j<=s+1;j++)
        {
            fprintf(fp,"  %4d",stu[i].score[j]);
        }
        fprintf(fp,"\n");
    }
}
/*按数据块写入*/
void WritetoFile2(STUDENT stu[],int n)
{
    FILE *fp;
    if((fp=fopen("student.txt","w"))==NULL)
    {
        printf("Failure to open student.txt!\n");
        exit(1);
    }
    fwrite(stu,sizeof(STUDENT),n,fp);
    fclose(fp);
}
/*读入文件返回学生人数 */
void ReadfromFile(STUDENT stu[],int*n,int*s)
{
    FILE*fp;
    int i,j;
    if((fp=fopen("student.txt","r"))==NULL)
    {
        printf("Failure to open student.txt!\n");
        exit(2);

    }
    fscanf(fp,"%d\t%d",n,s);
    for(i=0;i<*n+2;i++)
    {
        fscanf(fp,"%7ld %7s",&stu[i].studentID,stu[i].studentName);
        for(j=0;j<=*s+1;j++)
        {
            fscanf(fp,"  %4d",&stu[i].score[j]);
        }

    }
    printf("Total student is %d.\n",*n);
}
/*按数据块读出*/
int ReadfromFile2(STUDENT stu[])
{
    FILE*fp;
    int i;
    if((fp=fopen("student.txt","r"))==NULL)
    {
        printf("Failure to open student.txt!\n");
        exit(2);

    }
    for(i=0;!feof(fp);i++)
    {
        fread(&stu[i],sizeof(STUDENT),1,fp);
    }
    fclose(fp);
    printf("Total student is %d.\n",i-1);
    return i-1;
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
    /*第n+1个结构体保存总分；第n+2个结构体保存平均分*/
    strcpy(stu[n].studentName,"total");
    strcpy(stu[n+1].studentName,"average");
        printf("\n1.Input record\n");
        printf("2.Calculate total and average score of every course\n");
        printf("3.Calculate total and average score of every student\n");
        printf("4.Sort in descending order by total score of every student\n");
        printf("5.Sort in ascending  order by total score of every student\n");
        printf("6.Sort in ascending  order by number\n");
        printf("7.Sort in dictionary order by name\n");
        printf("8.Search by number\n");
        printf("9.Search by name\n"
               "10.Statistic analysis for every course\n"
               "11.List record\n"
               "12.Write to a file\n"
               "13.Read form a file\n"
               "0.Exit\n\n"
               "press enter to start\n");
    do{
        while(getchar()!='\n');
        printf("Please enter the order:\n");
        scanf("%d",&order);
        if(order==1)
        {
            do{
                printf("please input the number of subjects(<=8) and students(<=30):\n");
                scanf("%d%d",&s,&n);
            }while(n>30||n<=0||s<=0||s>9);
            InputRecord(stu,n,s);
            /*第n+1个结构体保存总分；第n+2个结构体保存平均分*/
            strcpy(stu[n].studentName,"total");
            strcpy(stu[n+1].studentName,"average");
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
        else if(order==12)
        {
            WritetoFile(stu,n+2,s);
        }
        else if(order==13)
        {
            ReadfromFile(stu,&n,&s);
            PrintRecord(stu,n,s);
        }
        else if(order!=0)
        {
            printf("wrong input.\n");
        }
    }while(order!=0);
    return 0;
}
