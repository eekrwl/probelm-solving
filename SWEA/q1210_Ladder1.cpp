#include <stdio.h>
int map[101][101];
int visit[101][101];
int x,y;
void input()
{
    x=99;
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            scanf("%d",&map[i][j]);
            if(i==99)
            {
                if(map[i][j]==2)
                    y=j;
            }
        }
    }
}
void resetVisit()
{
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            visit[i][j]=0;
        }
    }
}
int solution()
{
    visit[x][y]=1;
    while(x!=0) //다 올라갈때까지 반복
    {
        if(y-1>=0 && map[x][y-1]==1 && visit[x][y-1]==0) //왼쪽으로 갈 수 있다.
        {
            visit[x][y-1]=1;
            y-=1;
            
        }
        else if(y+1<100 && map[x][y+1]==1 && visit[x][y+1]==0) //오른쪽으로 갈 수 있다.
        {
            visit[x][y+1]=1;
            y+=1;
        }
        else if(x-1>=0 && map[x-1][y]==1 && visit[x-1][y]==0)
        {
            visit[x-1][y]=1;
            x-=1;
        }
    }
    return y;
}
int main()
{
    for(int test_case=1;test_case<=10;test_case++)
    {
        int t;
        scanf("%d",&t);
        input();
        resetVisit();
        int res=solution();
        printf("#%d %d\n",t,res);
    }
    return 0;
}
