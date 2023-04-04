#include <bits/stdc++.h>
#define ll long long
#define oo LLONG_MAX
#define ii pair<int,int>
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define BIT(x,i) ((x) >> (i)) & 1   /// kiem tra bit thu i cua x co bang 1 hay khong
#define MASK(i) (1LL << (i))  /// dich 1 qua i don vi

using namespace std;
const int NM=50;
ll m,n,q,maxx=-oo,res=oo,coutn=0;
ll c[NM]; /// luu cac gio hoc xung dot nhau;
ll deleted[NM],dem[NM],ans[NM];
vector <int> teach[NM];
pair <int,int> u[NM];

void readfile(){
    freopen("BCADIF.INP","r",stdin);
    freopen("BCADIF.OUT","w",stdout);
    cin >> m >> n;
    for(int i=1;i<=m;i++){
        ll u; cin >> u;
        for(int j=1;j<=u;j++){
            ll v; cin >> v;
            teach[v].push_back(i);
        }
    }
    cin >> q;
    for(int i=1;i<=q;i++){
        ll u,v;
        cin >> u >> v;
        c[u]|=MASK(v); c[v]|=MASK(u);
    }
    for(int i=1;i<=n;i++){
        u[i].first=i;
        u[i].second=teach[i].size();
    }
}
bool tmp(ll a,ll b){
    return dem[a] < dem[b];
}
void dp(ll x,ll y){
    coutn++;
    sort(teach[x].begin(),teach[x].end(),tmp);
    for(int i=0;i<teach[x].size();i++){
        ll t=teach[x][i];
        if(BIT(deleted[t],x)==1) continue;
        if(dem[t]+1>=res) break;
        else {
            dem[t]++;
            maxx=max(maxx,dem[t]);
            if(coutn==n) res=min(res,maxx);
            deleted[t]|=c[x];
            ll tam=deleted[t],luu=maxx;
            dp(u[y+1].first,y+1);
            dem[t]--;
            deleted[t]=tam;
            maxx=luu;
        }
    }
    coutn--;
    return;
}
bool cmp(ii a,ii b){
    return a.second > b.second;
}
void xuli(){
    sort(u+1,u+1+n,cmp);
    dp(u[1].first,1);
    cout << res;
}
int main(){
    FastIO
    readfile();
    xuli();
    return 0;
}
