#include <bits/stdc++.h>
#define ll long long
#define oo 1e18
#define FastIO ios:: sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e3+10;
ll n;
ll a[NM][NM],s[NM],k[NM];
vector <int> tc[NM];
///---------------------------------------------------------------------------///
struct Data
{
    ll v,w;
    bool inline operator < (const Data &A) const {
        return w>A.w;
    }
};
priority_queue <Data> pq;


void readfile(){
    freopen("LOCKDOWN.INP","r",stdin);
    freopen("LOCKDOWN.OUT","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    for(int i=1;i<=n;i++) s[i]=oo;
}
ll dijtra(){
    ll t[NM],dem=0;
    memset(t,0x3f,sizeof(t));
    t[1]=0;
    pq.push({1,0});
    while(!pq.empty()){
        ll u=pq.top().v, w=pq.top().w;
        pq.pop();
        for(int i=1;i<=n;i++){
            if(i!=u && t[i]>w+a[u][i] && a[u][i]!=-1){
                t[i]=w+a[u][i];
                pq.push({i,t[i]});
            }
        }
    }
    for(int i=1;i<=n;i++) if(t[i]>s[i]) dem++;
    return dem;
}
void trace(ll x,ll i){
    tc[i].push_back(x);
    if(k[x]!=0) trace(k[x],i);
    else return;
}
void xuli(){
    ll res=0;
    s[1]=0;
    pq.push({1,0});
    while(!pq.empty()){
        ll u=pq.top().v, w=pq.top().w;
        pq.pop();
        for(int i=1;i<=n;i++){
            if(i!=u && s[i]>w+a[u][i] && a[u][i]!=-1){
                s[i]=w+a[u][i];
                k[i]=u;
                pq.push({i,s[i]});
            }
        }
    }
    for(int i=2;i<=n;i++) trace(i,i);
    for(int v=2;v<=n;v++)
    for(int u=tc[v].size()-1;u>0;u--){
        ll i=tc[v][u], j=tc[v][u-1];
        if(i!=j && a[i][j]!=-1){
            ll tam=a[i][j];
            a[i][j]=-1;
            res=max(res,dijtra());
            a[i][j]=tam;
        }
    }
    cout << res;
}
int main(){
    FastIO
    readfile();
    xuli();
    return 0;
}
