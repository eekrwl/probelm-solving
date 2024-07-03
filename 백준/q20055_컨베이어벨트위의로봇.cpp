#include <stdio.h>
int n,k,a[201];
int robot[201];
int in,out;

void input();
void step1_beltRotation();
void step2_moveRobots();
void step3_addRobot();

int main()
{
    int step=0;
    input();

    while(1)
    {
        step++;
        step1_beltRotation();
        step2_moveRobots();
        step3_addRobot();
        
        int zeroCnt=0;
        for(int i=0;i<n*2;i++)
            if(a[i]==0) zeroCnt++;
        if(zeroCnt>=k) break;
    }
    printf("%d",step);
    return 0;
}
void step3_addRobot()
{
    if(a[in]>0)
    {
        robot[in]=1;
        a[in]--;
    }
}
void step2_moveRobots()
{
    int i=out-1;
    if(i==-1) i=n*2-1;
    while(i!=in)
    {
        if(robot[out]==1)
            robot[out]=0;
        int next=(i+1)%(n*2);
        if(robot[i]==1 && robot[next]==0 && a[next]>0) //다음칸 로봇없고 내구도 1이상
        {
            robot[i]=0;
            robot[next]=1;
            a[next]--;
        }
        
        i--;
        if(i==-1) i=n*2-1;
    }
}
void step1_beltRotation()
{
    in--;
    if(in==-1)
        in=n*2-1;
    out--;
    if(out==-1)
        out=n*2-1;
}
void input()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n*2;i++)
        scanf("%d",&a[i]);
    in=0;
    out=n-1;
}
