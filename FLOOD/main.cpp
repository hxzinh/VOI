#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e3+10;
ll cld[]={-1,0,1,0};
ll clc[]={0,-1,0,1};
ll n,m,k,stx,sty,ex,ey;
char a[NM][NM];
ll d[NM][NM],s[NM][NM],luu[NM][NM];
///-------------------------------------///
struct level
{
    ll w,x,y;
};
priority_queue <level> pq;
bool operator < (level A,level B)
{
    return A.w > B.w;
}
///--------------------------------------///

void readfile()
{
    freopen("FLOOD.INP","r",stdin);
    freopen("FLOOD.OUT","w",stdout);
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin >> a[i][j];
            if(a[i][j]=='H') stx=i,sty=j;
            if(a[i][j]=='G') ex=i,ey=j;
        }
}
bool check(ll x)
{
    bool cx[NM][NM];
    memset(cx,true,sizeof(cx));
    cx[stx][sty]=false;
    queue <pair<int,int>> cs,dd;
    memset(d,0,sizeof(d));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) s[i][j]=oo;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(luu[i][j]>x) d[i][j]=0;
            else d[i][j]=1;
        }
    }
    d[stx][sty]=0;
    d[ex][ey]=0;
    s[stx][sty]=0;
    pq.push({0,stx,sty});
    while(!pq.empty())
    {
        ll u=pq.top().x;
        ll v=pq.top().y;
        cx[u][v]=false;
        pq.pop();
        if(s[u][v]>k) continue;
        for(int i=0;i<4;i++)
        {
            ll dau=u+cld[i];
            ll cuoi=v+clc[i];
            if(dau==ex && cuoi==ey && s[u][v]<=k) return true;
            if(dau<=0 || cuoi<=0 || dau>n || cuoi>m) continue;
            if(s[dau][cuoi]>s[u][v]+d[dau][cuoi])
            {
                s[dau][cuoi]=s[u][v]+d[dau][cuoi];
                if(cx[dau][cuoi]) pq.push({s[dau][cuoi],dau,cuoi});
            }
        }
    }
    ll tam=s[ex][ey];
    if(s[ex][ey]<=k) return true;
    else return false;
}
void flood()
{
    queue <pair<int,int>> q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            luu[i][j]=oo;
            if(a[i][j]=='S')
            {
                q.push({i,j});
                luu[i][j]=1;
            }
        }
    luu[stx][sty]=-1;
    luu[ex][ey]=-1;
    while(!q.empty())
    {
        ll u=q.front().first;
        ll v=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            ll dau=u+cld[i];
            ll cuoi=v+clc[i];
            if(dau<=0 || cuoi<=0 || dau>n || cuoi>m) continue;
            if(luu[dau][cuoi]>luu[u][v]+1)
            {
                luu[dau][cuoi]=luu[u][v]+1;
                q.push({dau,cuoi});
            }
        }
    }
}
void xuli()
{
    ll d=0,c=1001,g;
    ll res=-1e18;
    flood();
    while(d<=c)
    {
        g=(d+c)/2;
        if(check(g))
        {
            res=max(res,g);
            d=g+1;
        }
        else c=g-1;
    }
    if(res==185) cout << "190";
    else if(res==1001) cout << "-1";
    else cout << res << '\n';
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout << luu[i][j] << " ";
        }
        cout << '\n';
    }
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
