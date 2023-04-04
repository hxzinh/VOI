#include <bits/stdc++.h>
#define ll long long
#define oo 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=3e5+10;
const int NMODE=6e5;
const int LOG=19;
ll sub,n,q,s[NM];
ll high[NM],par[NM][20];
bool cx[NM];

struct Data{
    ll v,w;
};
struct Distane{
    ll u,cost;
    bool inline operator < (const Distane &A) const {
        return cost > A.cost;
    }
};
vector <Data> a[NM];

/*void dijtra(){
    for(int i=1;i<=n;i++) s[i]=oo;
    s[1]=0; s[0]=0;
    priority_queue <Distane> pq;
    pq.push({1,0});
    while(!pq.empty()){
        ll u=pq.top().u, cost=pq.top().cost;
        pq.pop();
        for(int i=0;i<a[u].size();i++){
            ll v=a[u][i].v, w=a[u][i].w;
            if(s[v]>s[u]+w){
                s[v]=s[u]+w;
                pq.push({v,s[v]});
            }
        }
    }
}*/
void progress(){
    s[1]=0;
    for(int i=2;i<n;i++){
            ll w;
        if(a[i][0].v < a[i][1].v) w=a[i][0].w;
        else w=a[i][1].w;
        s[i]=w+s[i-1];
    }
    s[n]=a[n][0].w+s[n-1];
}
void readfile(){
    freopen("DISTANCE.INP","r",stdin);
    freopen("DISTANCE.OUT","w",stdout);
    cin >> sub;
    cin >> n;
    for(int i=1;i<n;i++){
        ll u,v,w; cin >> u >> v >> w;
        a[u].push_back({v,w}); a[v].push_back({u,w});
    }
    cin >> q;
}
void dfs(ll x){
    for(Data u : a[x]){
        if(u.v == par[x][0]) continue;
        high[u.v]=high[x]+1;
        s[u.v] = s[x] + u.w;
        par[u.v][0]=x;
        dfs(u.v);
    }
}
void sub3(){
    for(int i=1;i<=LOG;i++){
        for(int j=1;j<=n;j++){
            par[j][i]=par[par[j][i-1]][i-1];
        }
    }
}
ll lca(ll u,ll v){
    if(high[v]>high[u]) return lca(v,u);
    for(int i=LOG;i>=0;i--)
        if(high[par[u][i]]>=high[v]) u=par[u][i];
    if(u==v) return u;
    for(int i=LOG;i>=0;i--){
        if(par[u][i]!=par[v][i]){
            u=par[u][i]; v=par[v][i];
        }
    }
    return par[u][0];
}
void xuli(){
    if(sub==2) progress();
    //else dijtra();
    high[1]=0;
    dfs(1);
    sub3();
    for(int i=1;i<=q;i++){
        ll u,v;
        cin >> u >> v;
        if(sub==3 || sub==1){
            ll fa = lca(u,v);
            ll ans=s[u]+s[v]-s[fa]*2;
            cout << ans << '\n';
        }
        else cout << abs(s[v]-s[u]) << '\n';
    }
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
