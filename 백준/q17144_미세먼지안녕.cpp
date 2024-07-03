#include <stdio.h>
int r,c,t;
int arr[51][51];
int air[2];

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void diffusion()
{
    int nextArr[51][51]={};
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][j]>0)
            {
                int diff=arr[i][j]/5;
                int diffCnt=0;
                for(int k=0;k<4;k++)
                {
                    int a=i+dx[k];
                    int b=j+dy[k];
                    if(a<0 || a>=r || b<0 || b>=c || arr[a][b]==-1) continue;
                    nextArr[a][b]+=diff;
                    diffCnt++;
                }
                nextArr[i][j]+=arr[i][j]-diffCnt*diff;
            }
            else if(arr[i][j]==-1) nextArr[i][j]=-1;
        }
    }
    
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            arr[i][j]=nextArr[i][j];
        }
    }
}
void wind()
{
    int upper[4][2]={
        {0,1},
        {-1,0},
        {0,-1},
        {1,0}
    };
    int down[4][2]={
        {0,1},
        {1,0},
        {0,-1},
        {-1,0}
    };
    
    //위쪽
    int dir=0;
    int line[210]={};
    int lineCnt=1;
    int x=air[0],y=1;
    while(arr[x][y]!=-1) //공기청정기 만날때까지
    {
        line[lineCnt++]=arr[x][y];
        x+=upper[dir][0];
        y+=upper[dir][1];
        if(x<0 || x>=r || y<0 || y>=c)
        {
            x-=upper[dir][0];
            y-=upper[dir][1];
            dir++;
            x+=upper[dir][0];
            y+=upper[dir][1];
        }
    }
    
    int inputCnt=0;
    x=air[0];
    y=1;
    dir=0;
    while(arr[x][y]!=-1) //공기청정기 만날때까지
    {
        arr[x][y]=line[inputCnt++];
        x+=upper[dir][0];
        y+=upper[dir][1];
        if(x<0 || x>=r || y<0 || y>=c)
        {
            x-=upper[dir][0];
            y-=upper[dir][1];
            dir++;
            x+=upper[dir][0];
            y+=upper[dir][1];
        }
    }
    
    //아래쪽 시작
    dir=0;
    lineCnt=1;
    x=air[1];
    y=1;
    while(arr[x][y]!=-1) //공기청정기 만날때까지
    {
        line[lineCnt++]=arr[x][y];
        x+=down[dir][0];
        y+=down[dir][1];
        if(x<0 || x>=r || y<0 || y>=c)
        {
            x-=down[dir][0];
            y-=down[dir][1];
            dir++;
            x+=down[dir][0];
            y+=down[dir][1];
        }
    }
    
    inputCnt=0;
    x=air[1];
    y=1;
    dir=0;
    while(arr[x][y]!=-1) //공기청정기 만날때까지
    {
        arr[x][y]=line[inputCnt++];
        x+=down[dir][0];
        y+=down[dir][1];
        if(x<0 || x>=r || y<0 || y>=c)
        {
            x-=down[dir][0];
            y-=down[dir][1];
            dir++;
            x+=down[dir][0];
            y+=down[dir][1];
        }
    }
    
    
    
    
}
int main()
{
    int airCnt=0;
    scanf("%d%d%d",&r,&c,&t);
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&arr[i][j]);
            if(arr[i][j]==-1)
            {
                air[airCnt++]=i;
            }
        }
    }
    for(int i=0;i<t;i++)
    {
        diffusion();
        wind();
    }
    
    int answer=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][j]!=-1)
                answer+=arr[i][j];
        }
    }
    printf("%d",answer);
    
    return 0;
}
