#include <stdio.h>
#include <math.h>
#include <queue>
using namespace std;
int n,r,d;
typedef struct st{
    int x,y;
}LOC;
LOC towers[51];
LOC enemy;
int map[51][51]; //distance, 0은 적, 1~n은 타워
int visited[51];
queue<int> que;
double answer=0;
double calcDistance(LOC a, LOC b)
{
    return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
double calcEnergy(int walk)
{
    double energy=d;
    for(int i=0;i<walk;i++)
    {
        energy/=2;
    }
    return energy;
}
void bfs()
{
    int walk=0;
    que.push(0);
    visited[0]=1;
    while(!que.empty())
    {
        int qSize=que.size();
        for(int i=0;i<qSize;i++)
        {
            int t=que.front();
            que.pop();
            for(int j=1;j<=n;j++)
            {
                if(visited[j]==0 && map[t][j]==1)
                {
                    answer+=calcEnergy(walk);
                    visited[j]=1;
                    que.push(j);
                }
            }
        }
        walk++;
    }
}

int main()
{
    scanf("%d%d%d%d%d",&n,&r,&d,&enemy.x,&enemy.y);
    towers[0].x=enemy.x;
    towers[0].y=enemy.y;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&towers[i].x,&towers[i].y);
        for(int j=0;j<i;j++)
        {
            double dis=calcDistance(towers[i], towers[j]);
            if(dis<=r)
            {
                map[i][j]=1;
                map[j][i]=1;
            }
        }
    }
    
    bfs();
    printf("%.2lf\n",answer);
    return 0;
}