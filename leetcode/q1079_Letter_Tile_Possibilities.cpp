#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int answer=0;
int alpabet[26]={};
void bt()
{
    for(int i=0;i<26;i++)
    {
        if(alpabet[i]>0)
        {
            alpabet[i]--;
            answer++;
            bt();
            alpabet[i]++;
        }
    }
}
int numTilePossibilities(string tiles)
{
    for(int i=0;i<tiles.length();i++)
    {
        alpabet[tiles[i]-'A']++;
    }

    bt();
}

int main()
{
    string tiles = "AAABBC";
   
    numTilePossibilities(tiles);
    cout << answer << endl;

    return 0;
}