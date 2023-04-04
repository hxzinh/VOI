#include <bits/stdc++.h>
#define ll long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define oo 999999999

using namespace std;
const int NM=1e5+10;
ll n,m,dem=0;
ll s[NM],t[NM],X[NM],Y[NM],L[NM];
bool cx[NM];

struct tien
{
    ll v,w;
};
vector<tien> a[NM];

struct Data
{
    ll u,cost;
};
bool operator < (const Data &A,const Data &B)
{
    return A.cost > B.cost;
}
priority_queue <Data> pq;

void readfile()
{
    freopen("UPGRADE.INP","r",stdin);
    freopen("UPGRADE.OUT","w",stdout);
    FastIO
    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        ll u,v,w;
        cin >> u >> v >> w;
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    for(int i=1;i<=n;i++)
    {
        s[i]=oo;
        t[i]=oo;
    }
    X[1]=1;
    Y[n]=1;
    memset(cx,true,sizeof(cx));
}
void distra1()
{
    s[1]=0;
    pq.push({1,0});
    while(pq.size()>0)
    {
        int u=pq.top().u, k=pq.top().cost;
        pq.pop();
        if(k != s[u]) continue;
        for(int i=0;i<a[u].size();i++)
        {
            int v=a[u][i].v;
            int uv=a[u][i].w;
            if(s[v]>k+uv)
            {
                s[v]=k+uv;
                X[v]=X[u];
                pq.push({v,s[v]});
            }
            else if(s[v]==k+uv) X[v]=X[v]+X[u];
        }
    }
}
void distra2()
{
    t[n]=0;
    pq.push({n,0});
    while(pq.size()>0)
    {
        int u=pq.top().u, k=pq.top().cost;
        pq.pop();
        if(k != t[u]) continue;
        for(int i=0;i<a[u].size();i++)
        {
            int v=a[u][i].v;
            int uv=a[u][i].w;
            if(t[v]>k+uv)
            {
                t[v]=k+uv;
                Y[v]=Y[u];
                pq.push({v,t[v]});
            }
            else if(t[v]==k+uv) Y[v]=Y[v]+Y[u];
        }
    }
}

void xuli()
{
    cx[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(cx[i]==true)
            if(s[i]+t[i]!=s[n]) cx[i]=false;
    }
    for(int i=2;i<=n;i++)
    {
        if(cx[i]==true && X[i]*Y[i]==X[n]*Y[1])
        {
            for(int j=0;j<a[i].size();j++)
            {
                ll v=a[i][j].v;
                ll k=X[v]*Y[v];
                if(k==X[i]*Y[i])
                {
                    dem++;
                    break;
                }
            }
        }
    }
    cout << dem;
}
int main()
{
    readfile();
    distra1();
    distra2();
    xuli();
    return 0;
}
