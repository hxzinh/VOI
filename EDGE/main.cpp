#include <bits/stdc++.h>
#define ll int
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e5+10;
ll n,m,dt=0;
ll d[NM],s[NM],B[NM];
bool cx[NM];
vector <int> a[NM],L[NM];
///----------------------------------------------------------///

void readfile()
{
    freopen("EDGE.INP","r",stdin);
    freopen("EDGE.OUT","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        ll u,v;
        cin >> u >> v;
        a[u].push_back(v); a[v].push_back(u);
    }
    for(int i=1;i<=n;i++) s[i]=oo;
    memset(cx,true,sizeof(cx));
    memset(d,0,sizeof(d));
}
void dfs(ll x)
{
    s[x]=0;
    queue <int> st;
    st.push(x);
    while(!st.empty())
    {
        ll u=st.front();
        if(cx[u]) d[dt]++;
        cx[u]=false;
        st.pop();
        for(int i=0;i<a[u].size();i++)
        {
            ll v=a[u][i];
            if(cx[v] && s[v]>s[u]+1)
            {
                s[v]=s[u]+1;
                st.push(v);
            }
        }
    }
}
void xuli()
{
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        if(cx[i])
        {
            dt++;
            dfs(i);
        }
    }
    ///cout << dt << '\n';
    ///for(int i=1;i<=n;i++) cout << d[i] << " ";
    if(dt>2 || dt==0) cout << res;
    else
    {
        if(dt==1)
        {
            ll canh=(n*(n-1))/2;
            for(int i=1;i<=n;i++) res+=canh-m;
        }
        else
        {
            res=d[1]*d[2]*(m-(d[1]+d[2]-2));
        }
        cout << res;
    }
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
