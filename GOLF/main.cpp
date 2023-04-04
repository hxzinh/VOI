#include <bits/stdc++.h>
#define ll long long
#define oo 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e3+10;
ll clx[]={0,0,-1,1};
ll cly[]={1,-1,0,0};
bool cx[NM][NM];
ll n,m;
ll s[NM][NM];
struct Data
{
    ll gol,d;
};
Data a[NM][NM];
///-----------------------------------------------------///
struct level
{
    ll u,v,w;
};

void readfile()
{
    freopen("GOLF.INP","r",stdin);
    freopen("GOLF.OUT","w",stdout);
    cin >> m >> n;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> a[i][j].d;
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> a[i][j].gol;
        }
    }
    memset(cx,true,sizeof(cx));
    for(int i=0;i<=m;i++)
        for(int j=0;j<=n;j++) s[i][j]=oo;
}
void BFS(ll d,ll c)
{
    ll h=-oo;
    queue <level> q;
    ll gx=oo,gy=oo;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++)
        if(a[i][j].gol==1) {
            gx=i;
            gy=j;
            break;
        }
        if(gx!=oo && gy!=oo) break;
    }
    q.push({d,c,0});
    ///cx[gx][gy]=false;
    while(!q.empty())
    {
        ll u=q.front().u;
        ll v=q.front().v;
        ll w=q.front().w;
        cx[u][v]=false;
        q.pop();
        for(int i=0;i<4;i++)
        {
            ll x=u+clx[i];
            ll y=v+cly[i];
            if(x<=0 || y<=0 || x>m || y>n) continue;
            if(s[x][y]>abs(a[u][v].d-a[x][y].d))
            {
                s[x][y]=abs(a[u][v].d-a[x][y].d);
                ll cost=max(w,s[x][y]);
                q.push({x,y,cost});
            }
        }
    }
}
void xuli()
{
    ll h=-oo    ;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j].gol==1) BFS(i,j);
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j].gol==1) h=max(h,s[i][j]);
        }
    }
    cout << h;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
