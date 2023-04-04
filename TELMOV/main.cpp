#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e5+10;
ll n,m,l,k,p;
ll s[NM],F[NM][15][15];
bool cx[NM],ok[NM][4][15];
struct Data
{
    ll v,w;
};
vector <Data> a[NM];
///-------------------------------///
struct level
{
    ll u,cost;
};
bool operator < (const level &A,const level &B)
{
    return A.cost > B.cost;
}
///--------------------------------///
struct State
{
    ll u,cost,length,last;
};
bool operator < (const State &A,const State &B)
{
    return A.cost > B.cost;
}

void readfile()
{
    freopen("TELMOV.INP","r",stdin);
    freopen("TELMOV.OUT","w",stdout);
    cin >> n >> m >> p >> l >> k;
    for(int i=1;i<=m;i++)
    {
        ll u,v,w;
        cin >> u >> v >> w;
        a[u].push_back({v,w}); a[v].push_back({u,w});
    }
    memset(cx,true,sizeof(cx));
    memset(ok,true,sizeof(ok));
    for(int i=1;i<=n;i++) s[i]=oo;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=15;j++)
            for(int z=0;z<=15;z++) F[i][j][z]=oo;
}
void dijtra()
{
    priority_queue <level> pq;
    s[1]=0;
    pq.push({1,0});
    while(!pq.empty())
    {
        ll u=pq.top().u, cost=pq.top().cost;
        cx[u]=false;
        pq.pop();
        for(int i=0;i<a[u].size();i++)
        {
            ll v=a[u][i].v, w=a[u][i].w;
            if(s[v]>cost+w && cx[v])
            {
                s[v]=cost+w;
                pq.push({v,s[v]});
            }
        }
    }
    cout << s[n];
}
void dijtratt()
{
    priority_queue <State> pq;
    F[1][0][k]=0;
    pq.push({1,0,0,k});
    while(!pq.empty())
    {
        ll u=pq.top().u, cost=pq.top().cost, last=pq.top().last, length=pq.top().length;
        cout << u << " " << cost << " " << length << " " << last << '\n';
        pq.pop();
        for(int i=0;i<a[u].size();i++)
        {
            ll v=a[u][i].v, w=a[u][i].w;
            if(F[v][0][last]>cost+w)
            {
                F[v][0][last]=cost+w;
                pq.push({v,cost+w,0,last});
            }
            if(F[v][length-1][last]>cost && length>0)
            {
                F[v][length-1][last]=cost;
                pq.push({v,cost,length-1,last});
            }
            if(F[v][length-1][last-1]>cost+p && last>0)
            {
                F[v][length-1][last-1]=cost+p;
                pq.push({v,cost+p,l-1,last-1});
            }
        }
    }
    ll res=oo;
    for(int i=0;i<=15;i++)
        for(int j=0;j<=15;j++) res=min(res,F[n][i][j]);
    cout << res;
}
void xuli()
{
    if(k==0) dijtra();
    else dijtratt();
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
