#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int n;
char map[7][7];
typedef struct st{
    int x,y;
}LOC;
LOC candidate[36];
int candidateCnt=0;
LOC teacher[6];
int teacherCnt;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool canGo()
{
    for(int i=0;i<teacherCnt;i++)
    {
        for(int j=0;j<4;j++)
        {
            int x=teacher[i].x;
            int y=teacher[i].y;
            while(1)
            {
                x+=dx[j];
                y+=dy[j];
                if(x<0 || x>=n || y<0 || y>=n)
                    break;
                if(map[x][y]=='O') break;
                if(map[x][y]=='S')
                    return false;
            }
        }
    }
    return true;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf(" %c",&map[i][j]);
            if(map[i][j]=='X')
            {
                candidate[candidateCnt].x=i;
                candidate[candidateCnt++].y=j;
            }
            else if(map[i][j]=='T')
            {
                teacher[teacherCnt].x=i;
                teacher[teacherCnt++].y=j;
            }
        }
    }

    int arr[36]={};
    for(int i=candidateCnt-1;i>=candidateCnt-3;i--)
    {
        arr[i]=1;
    }

    do {
        for(int i=0;i<candidateCnt;i++)
        {
            if(arr[i]==1)
            {
                map[candidate[i].x][candidate[i].y]='O';
            }
        }

        if(canGo())
        {
            printf("YES\n");
            exit(0);
        }

        for(int i=0;i<candidateCnt;i++)
        {
            if(arr[i]==1)
            {
                map[candidate[i].x][candidate[i].y]='X';
            }
        }
    } while(next_permutation(arr,arr+candidateCnt));
    printf("NO\n");
    return 0;
} 