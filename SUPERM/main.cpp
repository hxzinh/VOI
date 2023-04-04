#include <bits/stdc++.h>
#define ll long long
#define int long long
#define oo 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e6+5e4+10;
int sub,n,m,cnt=0;
int sp[NM],fa[NM],high[NM],tam=-1;
vector <int> a[NM];
bool cx[NM],ok[NM];

struct Super
{
    ll u,cost,check;
    bool inline operator < (const Super &A) const {
        return cost > A.cost;
    }
};
priority_queue <Super> pq;

void readfile(){
    freopen("superm.inp","r",stdin);
    freopen("superm.out","w",stdout);
    cin >> sub;
    cin >> n >> m;
    for(int i=1;i<n;i++){
        ll u,v;
        cin >> u >> v;
        a[u].push_back(v); a[v].push_back(u);
    }
    memset(cx,false,sizeof(cx));
    memset(ok,false,sizeof(ok));
    for(int i=1;i<=m;i++){
        cin >> sp[i]; cx[sp[i]]=true;
        pq.push({sp[i],0,1});
    }
    sort(sp+1,sp+m+1);
}
void danhdau(ll x){
    ok[x]=true;
    for(int u : a[x]){
        if(ok[u]) continue;
        if(cx[u]) cx[x]=true;
        danhdau(u);
        if(cx[u]) cx[x]=true;
    }
}
void dfs(ll x){
    ok[x]=true;
    for(int u : a[x]){
        if(cx[u] && !ok[u]){
            cnt++;
            high[u]=high[x]+1;
            if(high[u]>high[tam]) tam=u;
            else if(high[u]==high[tam]) tam=min(tam,u);
            dfs(u);
        }
    }
}
void xuli(){
    if(m==1){cout << sp[1] << '\n' << "0"; return;}
    tam=0;
    danhdau(sp[1]);
    memset(ok,false,sizeof(ok));
    dfs(sp[1]);
    ll t=tam;
    tam=0;
    memset(high,0,sizeof(high));
    memset(ok,false,sizeof(ok));
    dfs(t);
    ll res = cnt - high[tam];
    cout << min(tam,t) << '\n' << res;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
