#include <bits/stdc++.h>
#define ll long long
#define oo 1e18
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=300;
ll n,s[NM],a[NM][NM];
bool cx[NM];

struct trip
{
    ll v,w;
};
///-----------------------------------------------------///
struct Data
{
    ll u,w;
    /*bool operator < (const Data &A) const {
        return w > A.w;
    }*/
};
queue <Data> pq;

void readfile(){
    freopen("trip.inp","r",stdin);
    cin >> n;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
        cin >> a[i][j];
    for(int i=1;i<=n;i++) s[i]=oo;
    memset(cx,true,sizeof cx);
}
void xuli(){
    s[1]=0;
    pq.push({1,0});
    while(!pq.empty()){
        ll u=pq.front().u, cost=pq.front().w;
        pq.pop();
        if(!cx[u]) continue;
        cx[u]=false;
        for(int i=1;i<=n;i++){
            ll w=a[u][i];
            if(cx[i] && s[u]+w<s[i]){
                s[i]=s[u]+w;
                pq.push({i,s[i]});
            }
        }
    }
    cout << s[n];
}
int main(){
    readfile();
    xuli();
    FastIO
    return 0;
}
