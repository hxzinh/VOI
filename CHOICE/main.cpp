#include <bits/stdc++.h>
#define ll long long
#define d double
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=2*1e3;
ll n,m,S,N,D;
struct Data
{
    ll x,y,r,w;
};
Data a[NM],t[NM];

void readfile()
{
    freopen("CONCOR.INP","r",stdin);
    freopen("CONCOR.OUT","w",stdout);
    cin >> S >> N >> D;
    for(int i=1;i<=S;i++)
    {
        cin >> a[i].x >> a[i].y >> a[i].r >> a[i].w;
    }
    for(int i=1;i<=N;i++)
    {
        cin >> t[i].x >> t[i].y;
    }
    t[0].x=0;
    t[0].y=0;
}
void xuli()
{
    for(int i=0;i<=N;i++)
    {

    }
}
int main()
{
    FastIO
    readfile();
    return 0;
}
