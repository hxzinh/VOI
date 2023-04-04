#include <bits/stdc++.h>
#define ll long long
#define oo 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e5+10;
ll n,m,k,K[100];
ll d[100][100010],pos[100];
bool cx[NM];
struct Data
{
    ll v,cost;
};
vector <Data> a[NM];

struct level
{
    ll u,s;
};
priority_queue <level> pq;

bool operator < (const level &A,const level &B)
{
    return A.s > B.s;
}

void readfile()
{
    freopen("BUILD.INP","r",stdin);
    freopen("BUILD.OUT","w",stdout);
    cin >> n >> m >> k;
    memset(cx,true,sizeof(cx));
    for(int i=1;i<=k;i++)
    {
        cin >> K[i];
        pos[i]=i;
        cx[K[i]]=false;
    }
    for(int i=1;i<=m;i++)
    {
        ll u,v,w;
        cin >> u >> v >> w;
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++)
        for(int j=1;j<=n;j++) d[i][j]=oo;
}
void xuli()
{
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n;j++) d[i][j]=oo;
        d[i][K[i]]=0;
        pq.push({K[i],0});
        while(pq.size()>0)
        {
            ll u=pq.top().u;
            ll cost=pq.top().s;
            pq.pop();
            if(d[i][u]!=cost) continue;
            for(int j=0;j<a[u].size();j++)
            {
                ll v=a[u][j].v;
                ll w=a[u][j].cost;
                if(d[i][v]>d[i][u]+w)
                {
                    d[i][v]=d[i][u]+w;
                    pq.push({v,d[i][v]});
                }
            }
        }
    }
    ll res=oo;
    do
    {
        ll ans=oo;
        for(int i=1;i<=n;i++)
        {
            if(cx[i])
            {
                ans=min(ans,d[pos[1]][i]+d[pos[k]][i]);
            }
        }
        for(int i=1;i<=k;i++) ans+=d[pos[i]][K[pos[i+1]]];
        res=min(res,ans);
    } while(next_permutation(pos+1,pos+k+1));
    cout << res;
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
