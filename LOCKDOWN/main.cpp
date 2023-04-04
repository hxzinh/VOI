#include <bits/stdc++.h>
#define ll long long
#define oo 1e18
#define FastIO ios:: sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=5e2+10;
ll n;
ll a[NM][NM],s[NM];
ll t[NM];
string k;
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
void trace(ll x){
    k=char(x+48)+k;
    if(t[x]!=0) trace(t[x]);
    else return;
}
void xuli(){
    s[1]=0;
    pq.push({1,0});
    while(!pq.empty()){
        ll u=pq.top().v, w=pq.top().w;
        pq.pop();
        for(int i=1;i<=n;i++){
            if(a[u][i]!=0 && s[i]>w+a[u][i] && a[u][i]!=-1){
                s[i]=w+a[u][i];
                t[i]=u;
                pq.push({i,s[i]});
            }
        }
    }
    for(int i=2;i<=n;i++){
        k="";
        trace(i);
        for(int j=0;j<k.length();j++){
            ll u=int(k[j]-48);
            tc[i].push_back(u);
        }
    }
    ll res=-oo;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ll dem=0;
            if(a[i][j]==0 || a[i][j]==-1) continue;
            for(int u=2;u<=n;u++){
                for(int v=0;v<tc[u].size();v++){
                    ll x=tc[u][v], y=tc[u][v+1];
                    if(i==x && j==y){
                        dem++;
                        break;
                    }
                }
            }
            res=max(res,dem);
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
