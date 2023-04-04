#include <bits/stdc++.h>
#define ll int
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
///-------------------------------///
#define MASK(i) (1LL << (i))
#define BIT(x,i) (((x) >> (i)) & 1)

using namespace std;
ll clx[]={1,-1,0,0};
ll cly[]={0,0,1,-1};
const int NM=1e2+10;
ll r,c;
char a[NM][NM];
pair <int,int> start;
ll F[110][110][20];
string key="yrgb";
string door="YRGB";
///----------------------------///
struct State
{
    ll u,v,sta;
};

void readfile()
{
    freopen("MAZE.INP","r",stdin);
    freopen("MAZE.OUT","w",stdout);
    cin >> r >> c;
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            cin >> a[i][j];
            if(a[i][j]=='*') {
                start.first=i;
                start.second=j;
            }
        }
    }
    for(int i=0;i<=r;i++)
        for(int j=0;j<=c;j++)
            for(int z=0;z<=20;z++) F[i][j][z]=oo;
}
bool onBoard(ll x,ll y)
{
    ///kiem tra o x,y co trong bang ko;
    if(x<1 || x>r || y<1 || y>c) return false;
    return true;
}
void BFS()
{
    ll res=oo;
    queue <State> q;
    F[start.first][start.second][0]=0;
    q.push({start.first,start.second,0});
    while(!q.empty())
    {
        ll u=q.front().u;
        ll v=q.front().v;
        ll mask=q.front().sta;
        ///cout << u << " " << v << " " << mask << '\n';
        q.pop();
        if(a[u][v]=='X' && F[u][v][mask]!=oo)
        {
            cout << "Escape possible in "<< F[u][v][mask] << " steps.";
            return;
        }
        for(int i=0;i<4;i++)
        {
            ll x=u+clx[i];
            ll y=v+cly[i];
            if(!onBoard(x,y) || a[x][y]=='#') continue;
            if('A'<=a[x][y] && a[x][y]<= 'Z' && a[x][y]!='X')
            {
                for(int j=0;j<4;j++)
                    if(door[j]==a[x][y])
                        if(BIT(mask,j) && F[x][y][mask]>F[u][v][mask]+1 )
                        {
                            F[x][y][mask]=F[u][v][mask]+1;
                            q.push({x,y,mask});
                        }
            }
            else
            {
                int newMask=mask;
                for(int j=0;j<4;j++)
                    if(key[j]==a[x][y])
                        newMask=mask|MASK(j);
                if(F[x][y][newMask]>F[u][v][mask]+1)
                {
                    F[x][y][newMask]=F[u][v][mask]+1;
                    q.push({x,y,newMask});
                }
            }

        }
    }
    cout << "The poor student is trapped!";
}
int main()
{
    FastIO
    readfile();
    BFS();
    return 0;
}
