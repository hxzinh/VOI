#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e4+10;
ll n,m,k,A,B;
struct Data
{
    ll v,w,h;
};
vector <Data> a[NM];
Data s[NM];

struct level
{
    ll u,cost,h;
};
priority_queue <level> pq;

bool operator < (const level &A,const level &B)
{
    return A.cost < B.cost;
}

void readfile()
{
    freopen("HANHTRINH.INP","r",stdin);
    freopen("HANHTRINH.OUT","w",stdout);
    cin >> k >> n >> m;
    for(int i=1;i<=m;i++)
    {
        ll u,v,w,h;
        cin >> u >> v >> w >> h;
        a[u].push_back({v,w,h});
        a[v].push_back({u,w,h});
    }
    for(int i=1;i<=n;i++)
    {
        s[i].w=oo;
        s[i].h=-1;
    }
    cin >> A >> B;
}
void dijstra()
{
    s[A].w=0;
    s[A].h=k;
    pq.push({A,0,k});
    while(pq.size()>0)
    {
        ll u=pq.top().u;
        ll hp=pq.top().h;
        pq.pop();
        for(int i=0;i<a[u].size();i++)
        {
            ll v=a[u][i].v;
            ll w=a[u][i].w;
            ll h=a[u][i].h;
            if(s[v].w>s[u].w+w && hp-h>0)
            {
                s[v].w=s[u].w+w;
                s[v].h=hp-h;
                pq.push({v,s[v].w,s[v].h});
            }
        }
    }
    if(s[B].w!=oo) cout << s[B].w;
    else cout << -1;
}
void xuli()
{

}
int main()
{
    FastIO
    readfile();
    dijstra();
    return 0;
}
