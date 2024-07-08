#include <stdio.h>
#include <limits.h>
#include <queue>
using namespace std;

int map[101][101];
int cnt[101][101];
int n;
typedef struct st{
    int x,y;
}LOC;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void fillCntMaxNum()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cnt[i][j]=INT_MAX;
        }
    }
}

int solution()
{
    queue<LOC> que;
    que.push({0,0});
    cnt[0][0]=0;
    while(!que.empty())
    {
        LOC t=que.front();
        que.pop();
        for(int i=0;i<4;i++)
        {
            int a=t.x+dx[i];
            int b=t.y+dy[i];
            if(a<0 || a>=n || b<0 || b>=n) continue;
            if(cnt[a][b]>cnt[t.x][t.y]+map[a][b])
            {
                cnt[a][b]=cnt[t.x][t.y]+map[a][b];
                que.push({a,b});
            }
            
        }
    }
    return cnt[n-1][n-1];
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int test_case=1;test_case<=t;test_case++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%1d",&map[i][j]);
            }
        }
        fillCntMaxNum();
        int res=solution();
        printf("#%d %d\n",test_case,res);
    }
    return 0;
}
