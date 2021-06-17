#include <stdio.h>
#include<bits/stdc++.h>
#define MAX 10005
#define INF 0x3f3f3f3f

using namespace std;

typedef struct Disk_Scheduling
{
    double Trackhao;
    double Trackshu;

} DKSG;



DKSG ds[MAX];

double track[MAX];

int mark[MAX];



int input(int &n,double &now)

{
    int im;

    int Min = INF;

    printf("请输入所求磁道号个数和开始磁道号(用空格隔开!):\n");

    scanf("%d%lf",&n,&now);

    printf("请输入%d个磁道号(各磁道号之间用空格隔开!):\n",n);

    for(int i=0; i<n; i++)
    {
        scanf("%lf",&track[i]);

        double temp= fabs(track[i]-now);

        if(temp< Min)
        {
            Min =temp;

            im = i;

        }

    }

    return im;

}



void output(int n)

{
    printf("%s   %s\n","被访问的下一个磁道号","横跨磁道数");

    for(int i=0; i<n; i++)
    {
        printf("%12.2f %16.2f\n",ds[i].Trackhao,ds[i].Trackshu);

    }

}



void FCFS()

{
    int n;

    double now;

    input(n,now);

    for(int i=0; i<n; i++)
    {
        ds[i].Trackhao = track[i];

        ds[i].Trackshu = fabs(track[i]-now);

        now =track[i];

    }

    printf("\n先来先服务:\n");

    output(n);

}



void SSTF()

{
    memset(mark,0,sizeof(mark));

    int n;

    double now;

    int im =input(n,now);

    int cnt1,cnt2;

    double t1,t2;

    for(int i=0; i<n; i++)
    {
        int Min =INF;

        ds[i].Trackhao = track[im];

        ds[i].Trackshu = fabs(track[im]-now);

        now =track[im];

        mark[im] =1;

        for(int j=0; j<n; j++)
        {
            if(!mark[j])
            {
                double temp = fabs(track[j]-now);

                if(temp < Min)
                {
                    Min = temp;

                    im = j;

                }

            }

        }

    }

    printf("\n最短寻道时间优先:\n");

    output(n);

}



void SCAN()

{
    double retrack[MAX];

    int n;

    double now;

    input(n,now);

    sort(track,track+n);

    int locate =upper_bound(track,track+n,now) - track;

    int t = locate;

    int k,r;

    for(k=0; k<n-locate; k++)
    {
        retrack[k]= track[k+locate];

    }

    for(r=k; r<n; r++)
    {
        retrack[r]= track[--t];

    }

    for(int i=0; i<n; i++)
    {
        ds[i].Trackhao = retrack[i];

        ds[i].Trackshu = fabs(retrack[i]-now);

        now =retrack[i];

    }

    printf("\n扫描调度算法:\n");

    output(n);

}



void C_SCAN()

{
    int n;

    double now;

    input(n,now);

    sort(track,track+n);

    int locate =upper_bound(track,track+n,now) - track;

    int im;

    for(int i=0; i<n; i++)
    {
        im =(i+locate)%n;

        ds[i].Trackhao = track[im];

        ds[i].Trackshu = fabs(track[im]-now);

        now =track[im];

    }

    printf("\n循环扫描调度算法:\n");

    output(n);

}



int main()

{
    printf("%*s\n",80,"欢迎您！");

    int ca = 0;

    do
    {
        printf("\n%*s\n",80,"请选择磁盘调度算法或结束程序:");

        printf("0、结束程序\n1、先来先服务\n2、最短寻道时间优先\n3、扫描\n4、循环扫描\n");

        scanf("%d",&ca);

        if(ca == 1)
            FCFS();

        if(ca == 2)
            SSTF();

        if(ca == 3)
            SCAN();

        if(ca == 4)
            C_SCAN();

        printf("\n\n");

    }
    while(ca);

    return 0;

}

