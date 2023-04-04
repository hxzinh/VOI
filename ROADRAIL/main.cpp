#include <bits/stdc++.h>
#define ll long long
#define oo 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e6+5;
ll n,m,l,p;
ll s[2010][2000][3];
struct Data
{
    ll v,w;
};
vector <vector<Data>> a[2];

struct level
{
    ll u,trans,z,cost;
    bool operator < (const level &A)
    const {
        return cost > A.cost;
    }
};

priority_queue <level> pq;
/** bool operator < (const level &A,const level &B) const {
    return A.cost < B.cost;
} **/

void readfile()
{
    freopen("ROADRAIL.INP","r",stdin);
    freopen("ROADRAIL.OUT","w",stdout);
    cin >> n >> m >> l >> p;
    for(int i=0;i<2;i++) a[i].resize(n);
    for(int i=1;i<=m;i++)
    {
        ll u,v,w;
        cin >> u >> v >> w;
        a[0][u].push_back({v,w});
    }
    for(int i=1;i<=l;i++)
    {
        ll u,v,w;
        cin >> u >> v >> w;
        a[1][u].push_back({v,w});
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
            for(int z=0;z<2;z++)
                s[i][j][z]=oo;
    }
}
void dijtra()
{
    for(int i=0;i<2;i++)
    {
        s[0][0][i]=0;
        pq.push({0,0,i,0});
    }
    while(pq.size()>0)
    {
        ll u=pq.top().u;
        ll d=pq.top().z;
        ll t=pq.top().trans;
        pq.pop();
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<a[i][u].size();j++)
            {
                ll v=a[i][u][j].v;
                ll w=a[i][u][j].w;
                ll newd=t+(i!=d);
                if(newd==n) continue;
                if(s[v][newd][i]>s[u][t][d]+w)
                {
                    s[v][newd][i]=s[u][t][d]+w;
                    pq.push({v,newd,i,s[v][newd][i]});
                }
            }
        }
    }
}

void xuli()
{
    dijtra();
    for(int k=1;k<=p;k++)
    {
        ll u,v;
        ll res=oo;
        cin >> u >> v;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<2;j++)
                res=min(res,s[v][i][j]+u*i);
        }
        if(res==oo) cout << "-1" << '\n';
        else cout << res << '\n';
    }
}
int main()
{
    FastIO
    readfile();
    xuli();
    //cout << '\nTime: ' << clock() / (double)1000 <<"s";
    return 0;
}
